
#include <AntTweakBar.h>
#include <iostream>
#include <fstream>
#include <string>
#include "skeleton.h"
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;
Skeleton * tree;
class Tree
{
	Skeleton root;

};



void init(void)
{
	/* Use depth buffering for hidden surface elimination. */
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	gluPerspective( /* field of view in degree */45.0,
		/* aspect ratio */ 1.0,
		/* Z near */ 1.0, /* Z far */ 200.0);
	gluLookAt(2, 2, 5,  /* eye is at (0,0,5) */
		0.0, 0.0, 0.0,      /* center is at (0,0,0) */
		0.0, 1.0, 0.);      /* up is in positive Y direction */
	glMatrixMode(GL_MODELVIEW);
	
	//glTranslatef(0.0, 0.0, -1.0);
	//glRotatef(90, 1.0, 0.0, 0.0);
	//glRotatef(-45, 0.0, 1.0, 0.0);


}

void initDragon(void)
{

	/* Use depth buffering for hidden surface elimination. */
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	gluPerspective( /* field of view in degree */105.0,
		/* aspect ratio */ 1.0,
		/* Z near */ 1.0, /* Z far */ 100.0);

	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0, 25, 5,  /* eye is at (0,0,5) */
		0.0, 0.0, 0.0,      /* center is at (0,0,0) */
		0.0, 1.0, 0.);      /* up is in positive Y direction */
	//glTranslatef(0.0, 0.0, -1.0);
	//glRotatef(90, 1.0, 0.0, 0.0);
	//glRotatef(-45, 0.0, 1.0, 0.0);


}

void initDragon2(void)
{

	/* Use depth buffering for hidden surface elimination. */
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	gluPerspective( /* field of view in degree */105.0,
		/* aspect ratio */ 1.0,
		/* Z near */ 1.0, /* Z far */ 100.0);

	glMatrixMode(GL_MODELVIEW);
	gluLookAt(10,15, 20,  /* eye is at (0,0,5) */
		0.0, 0.0, 0.0,      /* center is at (0,0,0) */
		0.0, 1.0, 0.);      /* up is in positive Y direction */
	//glTranslatef(0.0, 0.0, -1.0);
	//glRotatef(90, 1.0, 0.0, 0.0);
	//glRotatef(-45, 0.0, 1.0, 0.0);


}
Skeleton* treeCreate()
{
	int root = 0;
	int a[2] = { -2, 0 };
	cout << a[1];
	int k = 0; //for counting {
	int j = 0;// for counting }

	bool jbool = true;
	bool ibool = true;
	ifstream myfile;
	string line;
	Skeleton * object = new Skeleton;
	Skeleton * tree;
	Skeleton * head;

	myfile.open("C:/Users/Paul G Mathew/Downloads/test (2).skel");
	//myfile.open("C:/Users/Paul G Mathew/Downloads/dragon.skel");
	if (myfile.is_open())
	{
		cout << "the file is open ";
		while (getline(myfile, line) && !myfile.eof())
		{
			cout << line << '\n';
			cout << line.size();

			string stringvalues = line;
			istringstream iss(stringvalues);
			istream_iterator<string> beg(iss), end;
			vector<string> tokens(beg, end);
			bool offsetbool = false;
			bool boxminbool = false;
			bool boxmaxbool = false;
			bool rotxlimitbool = false;
			bool rotylimitbool = false;
			bool rotzlimitbool = false;
			bool posebool = false;
			GLfloat a[3];
			GLfloat aa[2];
			int i = 0;
			int check = 0;
			for (auto& s : tokens)
			{
				// std::cout << '"' << s << '"' << '\n';
				check += 1;
				if (s == "root")
				{
					root = 1;
				}
				if (s == "}")
				{
					jbool = ibool;
					ibool = false;
					cout << "jbool}" << jbool << "\n";;
					cout << "ibool}" << ibool << "\n";;
					j += 1;

					if (ibool == false && jbool == false)
					{
						Skeleton * tt = new Skeleton();
						tt = tree->getParent();
						tree = tt;
					}

				}
				if (s == "{")
				{
					jbool = ibool;
					ibool = true;

					cout << "jbool" << jbool << "\n";;
					cout << "ibool" << ibool << "\n";;
					k += 1;
					if ( k == 1)
					{
						j = i;
						i = true;
						cout << "yes its a root";
						tree = new Skeleton();
						object = tree;
						root = 2;
					}
					else if (ibool == true && jbool == true && k != 1)
					{
						GLfloat * out;
						out = tree->getOffset();
						std::cout << "the offset object22 called " << out[0] << "\n";
						std::cout << "the offset object22 called " << out[1] << "\n";
						std::cout << "the offset object22 called " << out[2] << "\n";
						Skeleton * child = new Skeleton();
						child->setParent(tree);
						tree->setChild(child);
						tree = child;
						GLfloat * out2;
						Skeleton * temp = tree->getParent();
						out2 = temp->getOffset();
						std::cout << "the offset object33 called " << out2[0] << "\n";
						std::cout << "the offset object33 called " << out2[1] << "\n";
						std::cout << "the offset object33 called " << out2[2] << "\n";
					}
					else if (ibool == true && jbool == false && k != 1)
					{

						cout << "sibling";
						Skeleton * sibling = new Skeleton();
						Skeleton * temp = new Skeleton();
						temp = tree->getParent();
						sibling->setParent(temp);
						tree->setSibling(sibling);
						tree = sibling;
					}

				}
				if (s == "offset")
				{
					cout << "yes its an offset";
					offsetbool = true;
				}
				if (s == "boxmin")
				{
					cout << "yes its a boxmin";
					boxminbool = true;
				}
				if (s == "boxmax")
				{
					cout << "yes its a boxmax";
					boxmaxbool = true;
				}
				if (s == "rotxlimit")
				{
					cout << "yes its a rotxlimit";
					rotxlimitbool = true;
				}
				if (s == "rotylimit")
				{
					cout << "yes its a rotylimiy";
					rotylimitbool = true;
				}
				if (s == "rotzlimit")
				{
					cout << "yes its a rotzlimit";
					rotzlimitbool = true;
				}
				if (s == "pose")
				{
					cout << "yes its a pose";
					posebool = true;
				}
				if (offsetbool == true && check >= 2)
				{//int i = 0;
					a[i] = stod(s);
					i++;
				}
				if (boxminbool == true && check >= 2)
				{
					//int i = 0;
					a[i] = stod(s);
					i++;
				}
				if (boxmaxbool == true && check >= 2)
				{
					///	int i = 0;
					a[i] = stod(s);
					i++;
				}
				if (rotxlimitbool == true && check >= 2)
				{
					//int i = 0;
					aa[i] = stod(s);
					i++;
				}
				if (rotylimitbool == true && check >= 2)
				{
					//int i = 0;
					aa[i] = stod(s);
					i++;
				}
				if (rotzlimitbool == true && check >= 2)
				{
					//int i = 0;
					aa[i] = stod(s);
					i++;
				}
				if (posebool == true && check >= 2)
				{
					//int i = 0;
					a[i] = stod(s);
					i++;
				}
			}
			if (offsetbool == true)
			{
				tree->setOffset(a);
				tree->setGlobalOffset(a);
			}
			if (boxminbool == true)
			{
				tree->setBoxmin(a);
			}
			if (boxmaxbool == true)
			{
				tree->setBoxmax(a);
			}
			if (rotxlimitbool == true)
			{
				tree->setRotxlimit(aa);
			}
			if (rotylimitbool == true)
			{
				tree->setRotylimit(aa);
			}
			if (rotzlimitbool == true)
			{
				tree->setRotzlimit(aa);
			}
			if (posebool == true)
			{
				tree->setPose(a);
			}


		}
	}
	else cout << "unable to open";
	//	GLfloat fb[3] = { 0, 1, -2.3 };
	//	Skeleton t;
	//	t.setOffset(fb);

	//	GLfloat * out

	//	out = t.getOffset();

	//std::cout << "the first out" << out[2];

	GLfloat * out;
	out = tree->getOffset();
	std::cout << "the offset object called " << out[0] << "\n";
	std::cout << "the offset object called " << out[1] << "\n";
	std::cout << "the offset object called " << out[2] << "\n";
	out = tree->getBoxmin();
	std::cout << "the boxmin object called " << out[0] << "\n";
	std::cout << "the boxmin object called " << out[1] << "\n";
	std::cout << "the boxmin object called " << out[2] << "\n";
	out = tree->getPose();
	std::cout << "the pose " << out[0] << "\n";
	std::cout << "the pose" << out[1] << "\n";
	std::cout << "the pose " << out[2] << "\n";

	Skeleton * sk = new Skeleton();
	sk = tree->getChild();
	out = sk->getOffset();
	std::cout << "the offset object called " << out[0] << "\n";
	std::cout << "the offset object called " << out[1] << "\n";
	std::cout << "the offset object called " << out[2] << "\n";
	out = sk->getBoxmin();
	std::cout << "the boxmin object called " << out[0] << "\n";
	std::cout << "the boxmin object called " << out[1] << "\n";
	std::cout << "the boxmin object called " << out[2] << "\n";


	Skeleton * rk = new Skeleton();
	rk = sk->getSibling();
	out = rk->getOffset();
	std::cout << "the offset object called " << out[0] << "\n";
	std::cout << "the offset object called " << out[1] << "\n";
	std::cout << "the offset object called " << out[2] << "\n";
	out = rk->getBoxmin();
	std::cout << "the boxmin object called " << out[0] << "\n";
	std::cout << "the boxmin object called " << out[1] << "\n";
	std::cout << "the boxmin object called " << out[2] << "\n";


	Skeleton * pk = new Skeleton();
	pk = rk->getChild();
	out = pk->getOffset();
	std::cout << "the offset object called " << out[0] << "\n";
	std::cout << "the offset object called " << out[1] << "\n";
	std::cout << "the offset object called " << out[2] << "\n";
	out = pk->getBoxmin();
	std::cout << "the boxmin object called " << out[0] << "\n";
	std::cout << "the boxmin object called " << out[1] << "\n";
	std::cout << "the boxmin object called " << out[2] << "\n";
	return tree;
}
void Skeletondraw(void)
{
	GLfloat* bma;
	GLfloat* bmi;
	GLfloat* off;
	Skeleton * temp;

	if (tree != NULL)
	{
		tree->drawskeleton();
		
		glPopMatrix();


	

	}

}
void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Skeletondraw();

	glutSwapBuffers();

	// Recall Display at next frame
	glutPostRedisplay();
}
int main(int argc, char *argv[]){
	tree = new Skeleton();
	tree = treeCreate();
	Skeleton* f = tree->getChild()->getSibling()->getSibling()->getChild();
	cout <<"printing offset of knee r" <<f->getOffset()[0] << f->getOffset()[1] << f->getOffset()[2];
	cout << "printing pose of knee r" << f->getPose()[0] << f->getPose()[1] << f->getPose()[2];
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 640);
	glutCreateWindow("");
	glutCreateMenu(NULL);
	glutDisplayFunc(Display);
	//initDragon();
	//initDragon2();
	init();
	glutMainLoop();
	return 0;



}