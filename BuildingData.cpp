
// VRML
#pragma warning( disable : 4250 ) 
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "antlrd.lib")
#pragma comment(lib, "regexd.lib")
#pragma comment(lib, "openvrmld.lib")

#include "PreDefs.h"
#include "BuildingData.h"
#include "GeomElements.h"

CBuildingData::CBuildingData(void)
{
	m_3DBuildingVrts = new osg::Vec3Array;
	m_3DBuildingClrs = new osg::Vec3Array;
}

CBuildingData::~CBuildingData(void)
{
}

// load 3d data from vrml file
int CBuildingData::load_3d_data(std::string& fn)
{
	if (fn.empty())
		return 0;

	m_3DBuildingVrts->clear();
	m_3DBuildingClrs->clear();

	osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFile(fn.c_str());
	VertexVisitor vtea;
	loadedModel->accept(vtea);

	m_3DBuildingVrts->clear();
	m_3DBuildingClrs->clear();
	int vrtnum = (vtea.extracted_vrts)->size();
	for (int iV=0; iV<vrtnum; iV++)
	{
		m_3DBuildingVrts->push_back(vtea.extracted_vrts->at(iV));
		m_3DBuildingClrs->push_back(vtea.extracted_vrtclrs->at(iV));
	}
	std::cout << "Load 3D building point data number : " << vrtnum << std::endl;

	return vrtnum;
}