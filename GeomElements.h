#pragma once
//#include "PreDefs.h"

// OSG visitor
class VertexVisitor : public osg::NodeVisitor
{
public:
	osg::ref_ptr<osg::Vec3Array> extracted_vrts;
	osg::ref_ptr<osg::Vec3Array> extracted_vrtclrs;

	VertexVisitor() : osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN)
	{
		extracted_vrts = new osg::Vec3Array();
		extracted_vrtclrs = new osg::Vec3Array();
	}

	void apply(osg::Geode& geode)
	{
		int num = geode.getNumDrawables();
		for (unsigned int i=0; i<num; i++)
		{
			osg::Geometry* geom = dynamic_cast<osg::Geometry*> (geode.getDrawable(i));
			if (!geom)
			{
				std::cout << "geometry error" << std::endl;
				continue;
			}

			// vertices
			osg::Vec3Array* vrts = dynamic_cast<osg::Vec3Array*> (geom->getVertexArray());
			if (!vrts)
			{
				std::cout << "vertex error" << std::endl;
				continue;
			}
			extracted_vrts->insert(extracted_vrts->end(), vrts->begin(), vrts->end());

			// colors
			osg::Vec3Array* cols = dynamic_cast<osg::Vec3Array*> (geom->getColorArray());
			if (!cols)
			{
				std::cout << "color error" << std::endl;
				for (int i=0; i<vrts->size(); i++)
					extracted_vrtclrs->push_back(osg::Vec3(1, 0, 0));
				continue;
			}
			else 
				extracted_vrtclrs->insert(extracted_vrtclrs->end(), cols->begin(), cols->end());
		}
	}
};