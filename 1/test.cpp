#include <iostream>
#include <assert.h>

#include "Vector.h"

int main() 
{
        Vector<int> v(5);

        v.pushBack(1);
        assert(v[0] == 1);

        v.insertAt(0, 0);
        assert(v[0] == 0);

        v = v + v;
        assert(v.size() == 4);

        v.popBack();
        assert(v.size() == 3);

        Vector<int> v2 = v.clone();
        assert(v2.size() == 3);

        v.removeAll();
        assert(v.size() == 0);

        std::cout << "All tests passed successfully" << std::endl;

        return 0;
}