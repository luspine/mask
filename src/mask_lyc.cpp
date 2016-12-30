//============================================================================
// Name        : hello.cpp
// Author      : Yongchun Lu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <iostream>
//using namespace std;
//
//int main() {
//	cout << "Hello World!!!" << endl; // prints Hello World!!!
//
//	double mask[10];
//	memset(mask,0,sizeof(mask));
//	return 0;
//}
/* memset example */
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
#include <dlfcn.h>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdio>

#include "autodoc.h"
#include "b3dutil.h"
#include "cfsemshare.h"
#include "hvemtypes.h"
#include "iimage.h"
#include "ilist.h"
#include "imodconfig.h"
#include "mrcfiles.h"
#include "mrcslice.h"


#include "angleSampling.h"
using namespace std;




int main() {
//  char str[] = "almost every programmer should know memset!";
//  memset (str,'-',6);
//  puts (str);

	double **mymask;
	int nRow = 60;
	int nCol = 60;
	mymask = angleSampling(-60, 60, 30, nRow, nCol);
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCol; j++)
			cout << mymask[i][j] << " ";
		cout << endl;
	}
//  Mat_<float> sal = saliency.saliency( im );
//  ofstream fout;
//  fout.open("sal_value.txt");
//  fout<<sal.rows<<endl;
//  fout<<sal.cols<<endl;
//  for(int i=0;i<sal.rows;i++){
//      for(int j=0;j<sal.cols;j++){
//           fout<<sal.at<float>(i,j)<<endl;
//      }
//   }
//   fout << flush;
//   fout.close();
	int hight, row, col;
	register int i, j, k;
	srand((unsigned) time(NULL));

	cout << "输入三维数组高，行，列 : ";
	cin >> hight >> row >> col;
	//动态定义三维数组：
	double ***p3;
	p3 = new double **[hight];
	for (i = 0; i < hight; i++)
		p3[i] = new double*[row];
	for (i = 0; i < hight; i++)
		for (j = 0; j < row; j++)
			p3[i][j] = new double[col];
	//输入三维数组值：
	for (i = 0; i < hight; i++)
		for (j = 0; j < row; j++)
			for (k = 0; k < col; k++)
//	      p3[i][j][k] = rand()%10 ;
				p3[i][j][k] = mymask[j][k];
	//输出三维数组：
	cout << "输出三维数组" << endl;
	for (i = 0; i < hight; i++) {
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++)
				cout << p3[i][j][k] << ' ';
			cout << endl;
		}
		cout << endl;
	}
	//释放三维数组
	for (i = 0; i < hight; i++)
		for (j = 0; j < row; j++)
			delete[] p3[i][j];
	for (i = 0; i < hight; i++)
		delete[] p3[i];
	delete[] p3;


	//动态定义三维sphere
	double radius=5;        //radius of sphere
	int z_center=hight/2;   //center's coordinate in z axis
	int y_center=col/2;     //center's coordinate in y axis
	int x_center=row/2;     //center's coordinate in x axis

	double ***shpere;
	shpere = new double **[hight];
	for (i = 0; i < hight; i++)
		shpere[i] = new double*[row];
	for (i = 0; i < hight; i++)
		for (j = 0; j < row; j++)
			shpere[i][j] = new double[col];
	//输入三维数组值：
	for (i = 0; i < hight; i++)
		for (j = 0; j < row; j++)
			for (k = 0; k < col; k++){
				if(sqrt(((i-z_center)^2)+((j-x_center)^2)+((k-y_center)^2)) <= radius)
					shpere[i][j][k] = 1;
				else
					shpere[i][j][k] = 0;
			}
//				shpere[i][j][k] = mymask[j][k];
	//输出三维数组：
	cout << "输出三维sphere" << endl;
	for (i = 0; i < hight; i++) {
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++)
				cout << shpere[i][j][k] << ' ';
			cout << endl;
		}
		cout << endl;
	}
	//释放三维shpere
	for (i = 0; i < hight; i++)
		for (j = 0; j < row; j++)
			delete[] shpere[i][j];
	for (i = 0; i < hight; i++)
		delete[] shpere[i];
	delete[] shpere;


	//important:clean up memory,Release of two dimensional array
		for (int i = 0; i < nRow; i++) {
			delete[] mymask[i];
		}
		delete[] mymask;
		mymask = 0;


	//
		const char *infile="/home/lyc/ribosome/emd_4121.mrc";
		static MrcHeader ImageHeader;
		void *handle  = dlopen("./libiimod.so",RTLD_LAZY);
		void *handle2 = dlopen("./libcfshr.so",RTLD_LAZY);
		if(!handle)
		{
			printf("open lib error\n");
			cout<<dlerror()<<endl;
			return -1;
		}
		if(!handle2)
		{
			printf("open lib error\n");
			cout<<dlerror()<<endl;
			return -1;
		}
		typedef int (*mrc_head_read_t)(FILE *fin, MrcHeader *hdata);
		mrc_head_read_t mrc_head_read= (mrc_head_read_t) dlsym(handle, "mrc_head_read");

		typedef FILE (**iiFOpen_t)(const char *filename, const char *mode);
//		FILE (**iiFOpen_t)(const char *filename, const char *mode);
		iiFOpen_t iiFOpen=(iiFOpen_t)dlsym(handle2, "iiFOpen");

//		void exitError(const char *format, ...);
		typedef void (*exitError_t)(const char *format, ...);
		exitError_t exitError=(exitError_t)dlsym(handle2, "exitError");

		 if(!mrc_head_read)
		    {
		        cout<<dlerror()<<endl;
		        dlclose(handle);
		        return -1;
		    }
		 FILE *gfin  = NULL;
		 MrcHeader hdata;

//		 MrcHeader *hin = &ImageHeader;

		  /* Open input image, read header */
		  gfin = iiFOpen(infile, "rb");
		  if (gfin == NULL)
//			  cout<<"ould not open"<<infile<<endl;
		    exitError("Could not open %s", infile);
		  if (mrc_head_read(gfin, &hdata))
//			  cout<<"Reading header of"<<infile<<endl;
		    exitError("Reading header of %s", infile);
//		  free(infile);

		  cout<<hdata.pathname<<"file path"<<endl;

//		 hin->fp = iiFOpen(filename, "rb");
//		 if (!hin->fp){
////		    midas_error("Couldn't open", filename, 0);
//		    return(1);
//		  }
//
//		 if (mrc_head_read(hin->fp, hin)){
////		    qstr.sprintf("Could not read %s", filename);
//		    printf("Could not read %s", filename);
////		    midas_error(b3dGetError(), LATIN1(qstr), 0);
//		    return(1);
//		  }

		 dlclose(handle);
		 dlclose(handle2);


	return 0;
}
