//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Used to load .obj files.
//
//=============================================================================


#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <Math/vec.h>
#include "objectloader.h"


void loadObjFile(const char* filename, std::vector<Vec3>& vertexBuffer, std::vector<int>& indexBuffer) {
    /* Loads the .obj file specified at the filename location.
     * This only works for triangles.
     */
    // A good example [https://stackoverflow.com/questions/52824956/how-can-i-parse-a-simple-obj-file-into-triangles]

    
    // Clear buffers to avoid errors.
    vertexBuffer.clear();
    indexBuffer.clear();

    std::string lineStr;
    std::ifstream inFile(filename);

    while (std::getline(inFile, lineStr)) {
        std::istringstream lineSS(lineStr);
        std::string lineType;

        lineSS >> lineType;
        
        // vertex  v -0.500000 -0.500000 0.500000
        if (lineType == "v") {  
            Vec3 v;
            lineSS >> v.x >> v.y >> v.z;
            vertexBuffer.push_back(v);
            continue;
        }

        // texture
        //if (lineType == "vt");
        
        // normal
        //if (lineType == "vn");
        
        // face  f 1/1/1 2/2/1 3/3/1
        if (lineType == "f") {  
            std::string face;  // will get small groups  1/1/1
            while (lineSS >> face) {
                std::istringstream data(face);
                std::string v_index_str, t_index_str, n_index_str;  // vertex_index/texture_index/normal_index

                std::getline(data, v_index_str, '/');
                std::getline(data, t_index_str, '/');
                std::getline(data, n_index_str, '/');

                int v_index = atoi(v_index_str.c_str());
                v_index  = (  v_index >= 0 ?  v_index : vertexBuffer.size() +  v_index );  // The index can be a negative value for back of array
                indexBuffer.push_back(v_index);
                //.push_back((int)t_index_str);  // NO USE FOR THIS YET!
                //.push_back((int)n_index_str);  // NO USE FOR THIS YET!
            }
            // TODO: Could triangulate here if desired.
        }
    }
    return;
}
