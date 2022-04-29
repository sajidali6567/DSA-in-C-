#include<bits/stdc++.h>
using namespace std;

struct student {
	string name;
	int age;
	student(string name, int age): age(age), name(name)
	{
		cout << "called constructor";
	}
	CompareAge operator() (student const &a, student const &b) {
		return a.age < b.age;
	}
};

// operator overloading for max heap
// bool operator <(student const &a, student const &b) {
//	return a.age < b.age;
// }



int main() {
	priority_queue<student, vector<int>, CompareAge> pq;
	pq.push(student{"sajid", 24});
	pq.push(student{"neha", 22});
	pq.push(student{"nafish", 20});
	pq.push(student{"shahid", 30});
	pq.push(student{"Anavar", 40});
	pq.push(student("Anavar", 40));
	while(!pq.empty()) {
		student temp = pq.top();
		cout << temp.name << " " << temp.age << endl;
		pq.pop();
	}
}