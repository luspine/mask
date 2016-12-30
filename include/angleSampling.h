/*
 * angleSampling.h
 *
 *  Created on: Dec 5, 2016
 *      Author: lyc
 */

#ifndef ANGLESAMPLING_H_
#define ANGLESAMPLING_H_

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<cmath>
using namespace std;



#define PI 3.14159265

//function mask = angleSampling(startAng, endAng, samplingNum, nRow, nCol)%%
//startAng : 起始角
// endAng : 终止角
// samplingNum : 采样数(大于等于2)
// nRow : 模板行数
// nCol : 模板列数
// 举例 :
// mask = angleSampling(-60, 60, 30, 256, 256);
double **angleSampling(double startAng,double endAng,int samplingNum,int nRow,int nCol)
{

	double equAng=(endAng-startAng)/(samplingNum-1);
//	double angle[samplingNum];
//	memset(angle,0,sizeof(angle));
	double *angle = new double[samplingNum];
	for(int i=0;i<samplingNum;i++)
	{
		angle[i]=startAng + i*equAng;
	}
//	double mask[nRow][nCol];
	double **mask=0;
	mask=new double*[nRow];
	for(int i=0;i<nRow;i++)
	{
		mask[i]=new double[nCol];
	}
	//2D matrix initialization
	for(int i=0;i<nRow;i++)
		for(int j=0;j<nCol;j++)
			mask[i][j]=0;
//	memset(mask,0,sizeof(mask));
	int centerRow = ceil(nRow/2);
	int centerCol = ceil(nCol/2);

	for (int r = 0;r<nRow;r++)
	{
	    for (int c = 0;c<centerCol;c++)
	    {
	        int x0 = c-(nCol-1)/2;
	        int y0 = (nRow-1)/2-r;
	        for (int n = 0;n<samplingNum;n++)
	        {
	            double theta = angle[n];
	            if ((theta == 90 )&& (abs(x0)<1))
	            {
	                mask[r][c] = 1;
	                mask[nRow-1-r][c] = 1;
	            }
	            else
	            {
	                double k = tan(theta * PI / 180.0); // 斜率
//	                double dis = ((double)abs(k*x0-y0))/sqrt(k^2+1); // 原点到直线距离
	                double dis = abs(k*x0-y0)/sqrt(pow(k,2)+1); // 原点到直线距离
	                if (dis < 1)
	                {
	                    mask[r][c] = 1;
	                    mask[nRow-1-r][nCol-1-c] =1;
	                }
	            }
	        }
	      }
	  }
	delete [] angle;
	return mask;
}
#endif /* ANGLESAMPLING_H_ */
