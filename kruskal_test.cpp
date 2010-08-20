#include <cppunit/extensions/HelperMacros.h>
#include <QtCore>
#include <gmpxx.h>
#include "graph.h"
#include "kruskal.h"
#include "edge.h"
#include "vertex.h"

class KruskalTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( KruskalTest );
    CPPUNIT_TEST( test );
    CPPUNIT_TEST_SUITE_END();
    private:
        mpf_class weight( vector<Edge>& v )
        {
            mpf_class t = 0;
            for(vector<Edge>::iterator i = v.begin(); i != v.end(); ++i) {
                t += (*i).getCost();
            }
            return t;
        }
    public:
        void setUp()
        {
        }

        void tearDown() 
        {
        }

        void test()
        {
            QFile *f = new QFile("input/01_quadrado2009.txt");
            Graph g = Graph(f);
            vector<Edge>v = kruskal(g);

            CPPUNIT_ASSERT( v.size() == 8 );
            CPPUNIT_ASSERT( weight(v) == 32 );
		}
};

CPPUNIT_TEST_SUITE_REGISTRATION( KruskalTest );