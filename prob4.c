//
// Nonlinear optimization -- spring 2014
// Test problem 4: minimization with constraints
// 
// min f(x) = 3(x1-3)^2 + 2x2^2 + x1x2
// s.t. x1^2 + x2^2 <= 2
//               x => 0
//
// x* = (sqrt(2), 0)^T, f(x*) = 33-18sqrt(2) \approx 7.5442
//
//


#include <stdio.h>
#include <math.h>


//int a;
//double b;


int main(void)
{
  //float x, f;
  float x[2],y[2];
  float f, g[2], c[3], gc1[2], gc2[2], gc3[2];
  int nx;
  int i,j;

  nx = 2;

  x[0] = 0.0;
  x[1] = 0.0;



  FILE *inputf = fopen("./input.txt","rt");

  if ( inputf == NULL ) printf("Error in reading file input.txt \n");

  for (i=0;i<nx;i++)
    {
      //fscanf(inputf,"%f",&x);
      fscanf(inputf,"%f",&x[i]);

    }

  fclose(inputf);

  // objective function
  f = 3.0*pow(x[0]-3.0,2.0) + 2.0*pow(x[1],2.0) + x[0]*x[1];

  // constraint functions
  c[0] = pow(x[0],2.0) + pow(x[1],2.0);
  c[1] = x[0];
  c[2] = x[1];

  // gradient of f
  g[0] = 6.0*(x[0]-3.0) + x[1];
  g[1] = 4.0*x[1] + x[0];

  // gradient of the constraints
  gc1[0] = 2.0*x[0];
  gc1[1] = 2.0*x[1];

  gc2[0] = 1.0;
  gc2[1] = 1.0;

  gc3[0] = 1.0;
  gc3[1] = 1.0;

  //printf("f = %f \n", f);

  FILE *outputf = fopen("./output.txt","wt");

  if ( outputf == NULL ) printf("Error in opening file output.txt \n");
  fprintf(outputf, "%f\n",f);
  fprintf(outputf, "%f\n%f\n%f\n",c[0],c[1],c[2]);

  fprintf(outputf, "%f\n",g[0]);
  fprintf(outputf, "%f\n",g[1]);

  fprintf(outputf, "%f\n",gc1[0]);
  fprintf(outputf, "%f\n",gc1[1]);

  fprintf(outputf, "%f\n",gc2[0]);
  fprintf(outputf, "%f\n",gc2[1]);

  fprintf(outputf, "%f\n",gc3[0]);
  fprintf(outputf, "%f\n",gc3[1]);

  fclose(outputf);


  return 0;
}

