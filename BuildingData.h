#pragma once

class CBuildingData
{
public:
	CBuildingData(void);
	virtual ~CBuildingData(void);

	int load_3d_data(std::string& fn);

protected:

public:
	osg::ref_ptr<osg::Vec3Array>	m_3DBuildingVrts;		// 3D building point set
	osg::ref_ptr<osg::Vec3Array>	m_3DBuildingClrs;		// 3D building point color
	
	std::string			m_sFileDir;			// Directory path
};
