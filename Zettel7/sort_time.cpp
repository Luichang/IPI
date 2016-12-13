#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void printVector(std::vector<T> v){							// simple output template function
	for(auto i:v){
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

template <typename ElementType, typename LessThanFunctor>
void insertion_sort(std::vector<ElementType> &v, LessThanFunctor less_than){
	int test = 0;
	for(int k = 1; k < v.size(); ++k){
		ElementType current = v[k];
		int j = k;
		while(j > 0){
			if(less_than(current, v[j - 1])){							// using the code to sort provided, not much explanation needed
				v[j] = v[j - 1];
			}else{
				break;
			}
			--j;
		}
		v[j] = current;
	}
}
template <typename T>
double std_sort_time(std::vector<T> v){
	std::random_shuffle(v.begin(), v.end());
	auto start = std::chrono::high_resolution_clock::now();
	insertion_sort(v, [](auto i, auto j){return i < j;});
	auto stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = stop - start;
	return diff.count();
}

int main(){
	std::vector<int> sorted(19000);
	std::vector<int> antiSorted(sorted.size());
	std::vector<int> randomSorted(sorted.size());
	std::uniform_int_distribution<int> uniform_dist(1, sorted.size());
	int j = sorted.size();
	for(auto i = 0; i < sorted.size(); ++i){
		sorted[i] = i;
		antiSorted[i] = j;
		randomSorted[i] = i;
		--j;
	}
	std::random_shuffle(randomSorted.begin(), randomSorted.end());
	std::cout << "This vector was sorted the right way and took: " << std_sort_time(sorted) << " seconds" << std::endl;
	std::cout << "This vector was sorted the wrong way and took: " << std_sort_time(antiSorted) << " seconds" << std::endl;
	std::cout << "This vector was sorted randomly and took: " << std_sort_time(randomSorted) << " seconds";
}