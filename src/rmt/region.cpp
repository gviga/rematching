/**
 * @file        region.cpp
 * 
 * @brief       Implementation of class rmt::SurfaceRegion.
 * 
 * @author      Filippo Maggioli\n
 *              (maggioli@di.uniroma1.it, maggioli.filippo@gmail.com)\n
 *              Sapienza, University of Rome - Department of Computer Science
 * 
 * @date        2024-01-12
 */
#include <rmt/region.hpp>
#include <rmt/utils.hpp>


rmt::SurfaceRegion::SurfaceRegion(int pi) : rmt::SurfaceRegion(pi, std::numeric_limits<int>::max() - 1) { }
rmt::SurfaceRegion::SurfaceRegion(int pi, int pj) : rmt::SurfaceRegion(pi, pj, std::numeric_limits<int>::max()) { }

rmt::SurfaceRegion::SurfaceRegion(int pi, int pj, int pk)
{
    // m_NVerts = 0;
    // m_NEdges = 0;
    // m_NFaces = 0;
    m_chi = 0;

    rmt::RegionDictionary::OrderIndices(pi, pj, pk);
    m_Samples = { pi, pj, pk };
}

rmt::SurfaceRegion::SurfaceRegion(const rmt::SurfaceRegion& SR)
{
    // m_NVerts = SR.m_NVerts;
    // m_NEdges = SR.m_NEdges;
    // m_NFaces = SR.m_NFaces;
    m_chi = SR.m_chi;
    m_Samples = SR.m_Samples;
}

rmt::SurfaceRegion& rmt::SurfaceRegion::operator=(const rmt::SurfaceRegion& SR)
{
    // m_NVerts = SR.m_NVerts;
    // m_NEdges = SR.m_NEdges;
    // m_NFaces = SR.m_NFaces;
    m_chi = SR.m_chi;
    m_Samples = SR.m_Samples;

    return *this;
}

rmt::SurfaceRegion::~SurfaceRegion() { }


std::tuple<int, int, int> rmt::SurfaceRegion::GetSamples() const { return m_Samples; }

// int rmt::SurfaceRegion::NumVertices() const { return m_NVerts; }
// int rmt::SurfaceRegion::NumFaces() const    { return m_NFaces; }
// int rmt::SurfaceRegion::NumEdges() const    { return m_NEdges; }
int rmt::SurfaceRegion::EulerCharacteristic() const
{
    // return NumVertices() + NumFaces() - NumEdges();
    return m_chi;
}

// void rmt::SurfaceRegion::AddFace()          { m_NFaces += 1; }
// void rmt::SurfaceRegion::AddVertex()        { m_NVerts += 1; }
// void rmt::SurfaceRegion::AddEdge()          { m_NEdges += 1; }
// void rmt::SurfaceRegion::AddBoundaryEdge()  { m_NEdges += 1; m_NVerts += 1; }
// void rmt::SurfaceRegion::AddBoundaryFace()  { m_NFaces += 1; m_NVerts += 1; m_NEdges += 2; }
void rmt::SurfaceRegion::AddFace()          { m_chi += 1; }
void rmt::SurfaceRegion::AddVertex()        { m_chi += 1; }
void rmt::SurfaceRegion::AddEdge()          { m_chi -= 1; }
// void rmt::SurfaceRegion::AddBoundaryEdge()  { }
// void rmt::SurfaceRegion::AddBoundaryFace()  { }


bool rmt::operator==(const rmt::SurfaceRegion& SR1, const rmt::SurfaceRegion& SR2)
{
    return SR1.m_Samples == SR2.m_Samples;
}
bool rmt::operator!=(const rmt::SurfaceRegion& SR1, const rmt::SurfaceRegion& SR2)
{
    return SR1.m_Samples != SR2.m_Samples;
}
bool rmt::operator<=(const rmt::SurfaceRegion& SR1, const rmt::SurfaceRegion& SR2)
{
    return SR1.m_Samples <= SR2.m_Samples;
}
bool rmt::operator<(const rmt::SurfaceRegion& SR1, const rmt::SurfaceRegion& SR2)
{
    return SR1.m_Samples < SR2.m_Samples;
}
bool rmt::operator>=(const rmt::SurfaceRegion& SR1, const rmt::SurfaceRegion& SR2)
{
    return SR1.m_Samples >= SR2.m_Samples;
}
bool rmt::operator>(const rmt::SurfaceRegion& SR1, const rmt::SurfaceRegion& SR2)
{
    return SR1.m_Samples > SR2.m_Samples;
}