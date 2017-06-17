//
// Created by matematyk60 on 17.06.17.
//

#include <vector>
#include <iostream>

class Mat : public std::vector<double*>{
public:
    Mat(){}

    double *addRow(int size){
        this->emplace_back(new double[size]);
        sizes.emplace_back(size);
        double *p = this->at(this->size()-1);
        for(int i = 0 ; i < sizes.at(this->size()-1) ; i++){
            *(p+i) = 1;
        }
        return this->at(this->size()-1);
    }

    void deleteRow(int r) {
        if (r > this->size() || r < 1) {
            throw "InvalidIndex";
        }
        delete[] this->at(r - 1);
        this->erase(this->begin() + r - 1);
        sizes.erase(sizes.begin() +r-1);
    }

    double &operator()(int row, int col){
        double * p = this->at(row-1);
        if(col > sizes.at(row-1)){
            throw "InvalidIndex";
        }
        return *(p+col-1);
    }

    void Print(){
        for(int i = 0 ; i < this->size() ; i++){
            for(int j = 0 ; j < sizes[i] ; j++){
                std::cout<<*(this->at(i)+j) << " ";
            }
            std::cout << "\n";
        }
    }

    Mat operator +(Mat& m2){
        Mat answer;
        long lim1 = this->size();
        long lim2 = m2.size();
        int i1, i2;
        for(int i = 0; i < std::max(lim1,lim2) ; i++){
            if(i >= lim1){
                i1 = 0;
            } else{
                i1 = this->sizes[i];
            }
            if(i >= lim2){
                i2 = 0;
            } else{
                i2 = m2.sizes[i];
            }
            answer.addRow(std::max(i1, i2));
        }
        double v1, v2;
        for(int i = 0 ; i < answer.size() ; i++){
            lim1 = this->sizes[i];
            lim2 = m2.sizes[i];
            for(int j = 0 ; j < std::max(lim1,lim2) ; j++){
                if(j >= lim1){
                    v1 = 0;
                } else{
                    v1 = this->operator()(i+1,j+1);
                }
                if(j >= lim2){
                    v2 = 0;
                }else {
                    v2 = m2(i+1,j+1);
                }
                answer(i+1,j+1) = v1+v2;
            }
        }
        return answer;

    }

private:
    std::vector<int> sizes;
};


int main(){
    Mat f;
    f.addRow(3);
    f.addRow(5);
    f.addRow(7);
    f.addRow(4);
    f.addRow(1);
    Mat p;
    p.addRow(5);
    p.addRow(6);
    p.addRow(1);
    p.addRow(5);
    Mat w = f+p;
    w.Print();
}