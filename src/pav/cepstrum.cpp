#include <iostream>
#include <cmath>

#include <cepstrum.h>

using namespace std;

std::vector<float> cepstrum(const vector<float> &x) {
    ffft::FFTReal <float> fft_object (x.size());

    vector<float> c(x.size());
    float X[x.size()], x_[x.size()], c_[x.size()/2], modX[x.size()/2];
    float eps = 1e-20;
    int i;
    for(i = 0; i < x.size(); i++){
        x_[i] = x[i];
    }

    fft_object.do_fft (X, x_);

    modX[0] = log(X[0] * X[0] + eps);
    for(i = 1; i < (x.size()/2-1); i++){
        float re = X[i];
        float im = X[x.size()/2+i];
        modX[i] = log(re*re+im*im + eps);
    }
    modX[x.size()/2] = log(X[x.size()/2]*X[x.size()/2] + eps);    
    fft_object.do_ifft (modX, c_);
    fft_object.rescale (c_);

    for(i = 0; i < x.size()/2; i++){
        c[i] = c_[i];
    }
    return c;
}
