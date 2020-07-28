#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double xc,yc;
double xd,yd;
double a,b,c;
double q,w,e;
double k,dis;
const double pi = 3.14159265358979f;
double distance(double a,double b, double c,double d){
   return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   cout.precision(15);
   cin>>xc>>yc>>xd>>yd>>a>>b>>c>>q>>w>>e; // a,b,c : blue / q,w,e : red
   double d1, d2;
   d1 = distance(xc, yc, q, w);
   d2 = distance(xd, yd, q, w);
   if (abs(d1 - e) < 1e-8 && abs(d2 - e ) < 1e-8){
       double stoe = distance(xc, yc, xd, yd);
       printf("%lf\n", asin((stoe/2.)/e)*2*e);
       return 0;
   }
   else if (abs(d1 - e) < 1e-8){
       double ctoe = distance(q, w, xd, yd);
       double slope = sqrt(ctoe*ctoe - e*e);
       double cos = pi - acos(ctoe/e);
       double cc = e * cos;
       printf("%lf\n", slope + cc);
       return 0;
   }
   else if (abs(d2 - e) < 1e-8){
       double ctoe = distance(q, w, xc, yc);
       double slope = sqrt(ctoe*ctoe - e*e);
       double cos = pi - acos(ctoe/e);
       double cc = e * cos;
       printf("%lf\n", slope + cc);
       return 0;       
   }
   
   double z=xc-xd;
   double x=yc-yd;
   if(z!=0){
      k=-xc*((yc-yd)/(xc-xd))+yc;
      dis=abs(x*q-z*w+k*z)/sqrt(z*z+x*x);
   }
   else{
      k=-xc;
      dis=abs(q-xc);
   }
   double answer=0;
   double seta=acos(dis/e);
   double setaa=acos(e/sqrt((q-xc)*(q-xc)+(w-yc)*(w-yc)));
   answer+=sqrt((q-xc)*(q-xc)+(w-yc)*(w-yc))*sin(setaa);
   double setab=acos(e/sqrt((q-xd)*(q-xd)+(w-yd)*(w-yd)));
   answer+=sqrt((q-xd)*(q-xd)+(w-yd)*(w-yd))*sin(setab);
   double go=2*e*tan((2*seta-setaa-setab)/2)+answer;
   answer+=(2*seta-setaa-setab)*e;
   if(answer>go){
      answer=go;
   }
   cout<<answer;
   return 0;
}













