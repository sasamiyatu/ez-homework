
int main(){
  double  x0 = 0.0;
  double  xe = 4.0;
  double  t0 = 0.0;
  double  te = 1.0;
  double h = 0.50;
  double c = 2.0;
  double k = 0.1;
  int n = (xe - x0) / h;
  int n2 = n - 1;
  int nt = (te - t0) / k;

  double r = (c*k)/(h*h);
  double p = 2*(1+(1/r));
  double q = 2*(1-(1/r));

  cerr  << h << "\t" << k << "\t" << n << "\t" << nt << "\t" << r << endl;
  cerr  << p << "\t" << q << endl;

  double z[n+1][nt];

  for( int i=0; i<n; i++){
    z[i][0] = 1;
  }
  for( int j=0; j<nt; j++){
    z[0][j] = 0;
    z[n][j] = 0;
  }

  n2 x n2行 列 を 設 定(Ax=bのA)

  double A[n2][n2] = {{0}};

  for (int j = 0; j < nt; ++j) {
    double B[n2] = {0};
    for(int i = 0; i < n2; ++i) {
      if (i == 0) {
        B[i] = -z[0][j] + q*z[1][j] - z[2][j] - 0;
      } else if (i == n) {
         B[i] = -z[n-2][j] + q*z[n-1][j] - z[n][j] - 0;
      } else {
         B[i] = -z[i][j] + q*z[i+1][j] - z[i+2][j];
       }
    }    
  }

  各 時 刻 でb
  を 更 新 し 、 ガ ウ ス の 消 去 法 な ど で 連立1次 方 程 式 を 解 い てx
    を 計 算 し 、zを更新する。

  for( int j=0; j<nt; j++){
    for( int i=0; i<=n; i++){
      double x = x0 + i*h;
      fprintf( stdout , "%.4lf %.4lf\n", x, z[i][j]);
    }
    fprintf( stdout , "\n\n");
  }


}
