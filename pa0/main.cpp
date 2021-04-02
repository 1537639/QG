#include<cmath>
#include<Eigen/Core>
#include<Eigen/Dense>
#include<iostream>


int main(){

	Eigen::Vector3f vp(2.0f, 1.0f, 1.0f), result;
	Eigen::Matrix3f r, t;
	r << sqrt(2), -sqrt(2), 0,
		sqrt(2), -sqrt(2), 0.0f,
		0.0f, 0.0f, 1.0f;

	t << 1.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 2.0f,
		0.0f, 0.0f, 1.0f;

	result = t * r * vp;
	std::cout << "经过转化后的点为" << std::endl;
	std::cout << result << std::endl;

    system("pause");

    return 0;
}