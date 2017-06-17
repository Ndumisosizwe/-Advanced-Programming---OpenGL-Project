 #ifndef MODEL_OBJ2_H
 #define MODEL_OBJ2_H
 #include "string.h"

//Reads a set of .obj vertices, Normals and faces from an .obj file modeled in Blender
//Renders them using the method Draw()
class Model_OBJ2 {
  public:
	Model_OBJ2();
	~Model_OBJ2();
    float* calculateNormal(float* coord1,float* coord2,float* coord3 );
    int Load(char *filename);	// Loads the model
	void Draw();					// Draws the model on the screen
	void Release();				// Release the model

	float* normals;							// Stores the normals
    float* Faces_Triangles;					// Stores the triangles
	float* vertexBuffer;					// Stores the points which make the object
	long TotalConnectedPoints;				// Stores the total number of connected verteces
	long TotalConnectedTriangles;			// Stores the total number of connected triangles

};
 #endif // MODEL_OBJ2_H
