#include "stdafx.h"
#include <map>
#include "collision.h"
#include "colliable_object.h"

namespace Collision
{
	class BitmaskManager
	{
	public:

		static sf::Uint8 GetPixel(
			const CollidableObject& object,
			unsigned int x,
			unsigned int y)
		{
			if(x > object.size_.x || y > object.size_.y)
				return 0;

			return object.mask_[x + y * object.size_.x];
		}
	};

	BitmaskManager Bitmasks;

	bool PixelPerfectTest(
		const CollidableObject& Object1,
		const CollidableObject& Object2,
		sf::Uint8 AlphaLimit)
	{
		sf::FloatRect Intersection;
		if(Object1.getGlobalBounds().intersects(Object2.getGlobalBounds(),
		                                        Intersection))
		{
			sf::IntRect O1SubRect = Object1.getTextureRect();
			sf::IntRect O2SubRect = Object2.getTextureRect();

			// Loop through our pixels
			for(int i = Intersection.left; i < Intersection.left + Intersection.
			    width; i++)
			{
				for(int j = Intersection.top; j < Intersection.top + Intersection.
				    height; j++)
				{
					sf::Vector2f o1v = Object1.getInverseTransform().transformPoint(i, j);
					sf::Vector2f o2v = Object2.getInverseTransform().transformPoint(i, j);

					// Make sure pixels fall within the sprite's subrect
					if(o1v.x > 0 && o1v.y > 0 && o2v.x > 0 && o2v.y > 0 &&
						o1v.x < O1SubRect.width && o1v.y < O1SubRect.height &&
						o2v.x < O2SubRect.width && o2v.y < O2SubRect.height)
					{
						int x1 = (int)(o1v.x) + O1SubRect.left;
						int y1 = (int)(o1v.y) + O1SubRect.top;

						int x2 = (int)(o2v.x) + O2SubRect.left;
						int y2 = (int)(o2v.y) + O2SubRect.top;

						if((x1 > Object1.size_.x || y1 > Object1.size_.y) ? 0 : Object1.mask_[x1 + y1 * Object1.size_.x]
						   && (x2 > Object2.size_.x || y2 > Object2.size_.y) ? 0 : Object2.mask_[x2 + y2 * Object2.size_.x])
						{
							return true;
						}
					}
				}
			}
		}
		return false;
	}

	sf::Vector2f GetSpriteCenter(const sf::Sprite& Object)
	{
		sf::FloatRect AABB = Object.getGlobalBounds();
		return sf::Vector2f(AABB.left + AABB.width / 2.f,
		                    AABB.top + AABB.height / 2.f);
	}

	sf::Vector2f GetSpriteSize(const sf::Sprite& Object)
	{
		sf::IntRect OriginalSize = Object.getTextureRect();
		sf::Vector2f Scale = Object.getScale();
		return sf::Vector2f(OriginalSize.width * Scale.x,
		                    OriginalSize.height * Scale.y);
	}

	bool CircleTest(const sf::Sprite& Object1, const sf::Sprite& Object2)
	{
		sf::Vector2f Obj1Size = GetSpriteSize(Object1);
		sf::Vector2f Obj2Size = GetSpriteSize(Object2);
		float Radius1 = (Obj1Size.x + Obj1Size.y) / 4;
		float Radius2 = (Obj2Size.x + Obj2Size.y) / 4;

		sf::Vector2f Distance = GetSpriteCenter(Object1) -
				GetSpriteCenter(Object2);

		return (Distance.x * Distance.x + Distance.y * Distance.y <= (Radius1 +
			Radius2) * (Radius1 + Radius2));
	}

	class OrientedBoundingBox // Used in the BoundingBoxTest
	{
	public:
		OrientedBoundingBox(const sf::Sprite& Object)
		// Calculate the four points of the OBB from a transformed (scaled, rotated...) sprite
		{
			sf::Transform trans = Object.getTransform();
			sf::IntRect local = Object.getTextureRect();
			Points[0] = trans.transformPoint(0.f, 0.f);
			Points[1] = trans.transformPoint(local.width, 0.f);
			Points[2] = trans.transformPoint(local.width, local.height);
			Points[3] = trans.transformPoint(0.f, local.height);
		}

		sf::Vector2f Points[4];

		void ProjectOntoAxis(const sf::Vector2f& Axis, float& Min, float& Max)
		// Project all four points of the OBB onto the given axis and return the dotproducts of the two outermost points
		{
			Min = (Points[0].x * Axis.x + Points[0].y * Axis.y);
			Max = Min;
			for(int j = 1; j < 4; j++)
			{
				float Projection = (Points[j].x * Axis.x + Points[j].y * Axis.y);

				if(Projection < Min)
					Min = Projection;
				if(Projection > Max)
					Max = Projection;
			}
		}
	};

	bool BoundingBoxTest(const sf::Sprite& Object1, const sf::Sprite& Object2)
	{
		OrientedBoundingBox OBB1(Object1);
		OrientedBoundingBox OBB2(Object2);

		// Create the four distinct axes that are perpendicular to the edges of the two rectangles
		sf::Vector2f Axes[4] = {
			sf::Vector2f(OBB1.Points[1].x - OBB1.Points[0].x,
			             OBB1.Points[1].y - OBB1.Points[0].y),
			sf::Vector2f(OBB1.Points[1].x - OBB1.Points[2].x,
			             OBB1.Points[1].y - OBB1.Points[2].y),
			sf::Vector2f(OBB2.Points[0].x - OBB2.Points[3].x,
			             OBB2.Points[0].y - OBB2.Points[3].y),
			sf::Vector2f(OBB2.Points[0].x - OBB2.Points[1].x,
			             OBB2.Points[0].y - OBB2.Points[1].y)
		};

		for(int i = 0; i < 4; i++) // For each axis...
		{
			float MinOBB1, MaxOBB1, MinOBB2, MaxOBB2;

			// ... project the points of both OBBs onto the axis ...
			OBB1.ProjectOntoAxis(Axes[i], MinOBB1, MaxOBB1);
			OBB2.ProjectOntoAxis(Axes[i], MinOBB2, MaxOBB2);

			// ... and check whether the outermost projected points of both OBBs overlap.
			// If this is not the case, the Separating Axis Theorem states that there can be no collision between the rectangles
			if(!((MinOBB2 <= MaxOBB1) && (MaxOBB2 >= MinOBB1)))
				return false;
		}
		return true;
	}
}
