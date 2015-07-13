//skeleton.h
#include <iostream>
#include<glut.h>
using namespace std;
class Skeleton {
public:
	int key;

	bool isChild;
	bool isSibling;
	GLfloat offset[3];
	GLfloat boxmin[3];
	GLfloat boxmax[3];
	GLfloat rotxlimit[3];
	GLfloat rotylimit[3];
	GLfloat rotzlimit[3];
	GLfloat pose[3];
	string name;
	Skeleton* child;
	Skeleton* sibling;
	Skeleton* parent;
	GLfloat globalOffset[3];
	Skeleton()
	{
		key = -1;
		child = NULL;
		sibling = NULL;
		parent = NULL;
		for (int i = 0; i < 3; i++)
		{
	
		offset[i] = 0;
		boxmin[i] = -0.1;
		boxmax[i] = +0.1;
		pose[i] = 0;
		}
		rotxlimit[0] = rotylimit[0] = rotzlimit[0] = -100000;
		rotxlimit[1] = rotylimit[1] = rotzlimit[1] = 100000;


	}
	void setChild(Skeleton* thisChild)
	{
		child = thisChild;
	}
	void setSibling(Skeleton* thisSibling)
	{
		sibling = thisSibling;
	}
	void setParent(Skeleton* thisParent)
	{
		parent = thisParent;
	}

	Skeleton* getChild()
	{
		return child;
	}
	Skeleton* getSibling()
	{
		return sibling;
	}
	Skeleton* getParent()
	{
		return parent;
	}


	GLfloat * getOffset()
	{
		return offset;
	}
	void * setOffset(GLfloat  ioffset[])
	{
		for (int i = 0; i<3; i++){
			offset[i] = ioffset[i];
			cout <<" this is the offset"<< offset[i];

		}
		return 0;
	}
	GLfloat * getBoxmin()
	{
		return boxmin;
	}
	void * setBoxmin(GLfloat iboxmin[])
	{
		for (int i = 0; i<3; i++){
			boxmin[i] = iboxmin[i];
			//cout << offset[i];

		}
		return 0;

	}
	GLfloat * getBoxmax()
	{
		return boxmax;
	}
	void * setBoxmax(GLfloat iboxmax[]){
		for (int i = 0; i<3; i++){
			boxmax[i] = iboxmax[i];
			//cout << offset[i];
		}
		return 0;

	}

	GLfloat * getRotxlimit()
	{
		return rotxlimit;
	}

	void * setRotxlimit(GLfloat irotxlimit[])
	{

		for (int i = 0; i<3; i++){
			rotxlimit[i] = irotxlimit[i];
			//cout << offset[i];
		}
		return 0;

	}
	GLfloat * getRotylimit()
	{
		return rotylimit;
	}
	void * setRotylimit(GLfloat irotylimit[])
	{
		for (int i = 0; i<3; i++){
			rotylimit[i] = irotylimit[i];
			//cout << offset[i];
		}
		return 0;

	}
	GLfloat * getRotzlimit()
	{
		return rotzlimit;
	}
	void * setRotzlimit(GLfloat irotzlimit[])
	{
		for (int i = 0; i<3; i++){
			rotzlimit[i] = irotzlimit[i];
			//cout << offset[i];
		}
		return 0;
	}
	GLfloat * getPose()
	{
		return pose;
	}
	void * setPose(GLfloat ipose[])
	{
		for (int i = 0; i<3; i++){
			if (i == 0)
			{
				if (ipose[i] > rotxlimit[1])
				{
					pose[i] = rotxlimit[1];
				}
				else if (ipose[i] < rotxlimit[0])
				{
					pose[i] = rotxlimit[0];
				}
				else
					pose[i] = ipose[i];
			}
			if (i == 1)
			{
				if (ipose[i] > rotylimit[1])
				{
					pose[i] = rotylimit[1];
				}
				else if (ipose[i] < rotylimit[0])
				{
					pose[i] = rotylimit[0];
				}
				else
					pose[i] = ipose[i];
			}
			if (i == 2)
			{
				if (ipose[i] > rotzlimit[1])
				{
					pose[i] = rotzlimit[1];
				}
				else if (ipose[i] < rotzlimit[0])
				{
					pose[i] = rotzlimit[0];
				}
				else
					pose[i] = ipose[i];
			}
			
		}
		return 0;
	}
	GLfloat * getGlobalOffset()
	{
		return globalOffset;
	}
	void * setGlobalOffset(GLfloat globaloff[])
	{
		if (parent != NULL)
			{
		for (int i = 0; i < 3; i++){
			globalOffset[i] = globaloff[i] + parent->getGlobalOffset()[i];

		}
	}
		else
		{
			for (int i = 0; i < 3; i++){
				globalOffset[i] = globaloff[i];

			}
		}
		return 0;
	}
	string getName()
	{
		return name;
	}
	string setName(string namee)
	{

		cout << "joint name" << name;
		name = namee;
		return name;
	}
	void drawskeleton(void)
	{
		

			GLfloat v[8][3];
			cout <<"child offsets *******************"<< offset[0] << offset[1] << offset[2];
		/*	v[0][0] = v[1][0] = v[2][0] = v[3][0] = boxmin[0] + offset[0];//
			v[4][0] = v[5][0] = v[6][0] = v[7][0] = boxmax[0] + offset[0];//
			v[0][1] = v[1][1] = v[4][1] = v[5][1] = boxmin[1] + offset[1];//
			v[2][1] = v[3][1] = v[6][1] = v[7][1] = boxmax[1] + offset[1];//
			v[0][2] = v[3][2] = v[4][2] = v[7][2] = boxmin[2] + offset[2];//
			v[1][2] = v[2][2] = v[5][2] = v[6][2] = boxmax[2] + offset[2];//
			*/

			v[0][0] = v[1][0] = v[2][0] = v[3][0] = boxmin[0];//
			v[4][0] = v[5][0] = v[6][0] = v[7][0] = boxmax[0];//
			v[0][1] = v[1][1] = v[4][1] = v[5][1] = boxmin[1];//
			v[2][1] = v[3][1] = v[6][1] = v[7][1] = boxmax[1];//
			v[0][2] = v[3][2] = v[4][2] = v[7][2] = boxmin[2];//
			v[1][2] = v[2][2] = v[5][2] = v[6][2] = boxmax[2];//

			glPushMatrix();
			
			//glTranslatef(globalOffset[0], globalOffset[1], globalOffset[2]);
			glTranslatef(offset[0],offset[1],offset[2]);
			glRotatef(57.2957795*pose[2], 0.0, 0.0, 1.0);
			glRotatef(57.2957795*pose[1], 0.0, 1.0, 0.0);
			glRotatef(57.2957795*pose[0], 1.0, 0.0, 0.0);
			
			
		
			glBegin(GL_QUADS);
			glColor3f(1.0, 1.0, 1.0);
			glVertex3f(v[0][0], v[0][1], v[0][2]);
			glVertex3f(v[1][0], v[1][1], v[1][2]);
			glVertex3f(v[2][0], v[2][1], v[2][2]);
			glVertex3f(v[3][0], v[3][1], v[3][2]);
			glEnd();

			// Purple side - RIGHT
			glBegin(GL_QUADS);
			glColor3f(1.0, 0.0, 1.0);
			glVertex3f(v[4][0], v[4][1], v[4][2]);
			glVertex3f(v[5][0], v[5][1], v[5][2]);
			glVertex3f(v[6][0], v[6][1], v[6][2]);
			glVertex3f(v[7][0], v[7][1], v[7][2]);
			glEnd();

			//back
			glBegin(GL_QUADS);
			glColor3f(0.0, 1.0, 0.0);
			glVertex3f(v[2][0], v[2][1], v[2][2]);
			glVertex3f(v[1][0], v[1][1], v[1][2]);
			glVertex3f(v[5][0], v[5][1], v[5][2]);
			glVertex3f(v[6][0], v[6][1], v[6][2]);

			glEnd();

			// front
			glBegin(GL_QUADS);
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(v[0][0], v[0][1], v[0][2]);
			glVertex3f(v[4][0], v[4][1], v[4][2]);
			glVertex3f(v[7][0], v[7][1], v[7][2]);
			glVertex3f(v[3][0], v[3][1], v[3][2]);
			glEnd();



			// BOTTOM
			glBegin(GL_QUADS);
			glColor3f(1.0, 0.0, 0.0);
			glVertex3f(v[0][0], v[0][1], v[0][2]);
			glVertex3f(v[4][0], v[4][1], v[4][2]);
			glVertex3f(v[5][0], v[5][1], v[5][2]);
			glVertex3f(v[1][0], v[1][1], v[1][2]);
			glEnd();

			// top
			glBegin(GL_QUADS);
			glColor3f(1.0, 1.0, 0.0);
			glVertex3f(v[2][0], v[2][1], v[2][2]);
			glVertex3f(v[3][0], v[3][1], v[3][2]);
			glVertex3f(v[7][0], v[7][1], v[7][2]);
			glVertex3f(v[6][0], v[6][1], v[6][2]);

			glEnd();

			if (child!= NULL)
			{

				child->drawskeleton();
				glPopMatrix();
			//	if (child->getChild() == NULL && sibling== NULL)
			//	{
			//		if (child->getParent()->getSibling() != NULL)
			//		{
			//			child->getParent()->getSibling()->drawskeleton();
			//		}
				//return;
			}

		    if (sibling!= NULL)
			{
				 glPopMatrix();
				sibling->drawskeleton();

				//return;
			}
		//  glPopMatrix();//preference

			
			return;
	}



};