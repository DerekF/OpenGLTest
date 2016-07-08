#include<iostream>
#include "glm/glm.hpp"
#include "glm/vec3.hpp"

using namespace std;
using namespace glm;

int main() {

	cout << "This is a test." << endl;

	vec3 a = vec3(1.0f, 2.0f, 3.0f);
	a = glm::normalize(a);

	cout << "The vector length is " << glm::length(a) << endl;

	while (true);//loop forever
	return 0;
}