#include <random>
#include <iostream>											// using -std=c++14 for the lambda functions
#include <vector>
#include <algorithm>
#include <cassert>

template <typename T>
void printVector(std::vector<T> v){							// simple output template function
	for(auto i:v){
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

template <typename ElementType, typename LessThanFunctor>	// really? now they use camelCase?
bool check_sorted(std::vector<ElementType> &v, LessThanFunctor less_than){
	if(v.begin() == v.end()){
		return true;
	}	
	for(int k = 1; k < v.size(); ++k){
		ElementType current = v[k];
		int j = k;
		while(j > 0){
			if(less_than(current, v[j - 1])){				
				return false;
			}else{
				break;
			}
			--j;
		}
	}
	return true;
}

template <typename Iterator, typename LessThanFunctor>
bool check_sorted(Iterator begin, Iterator end, LessThanFunctor less_than){
	if(begin == end){
		return true;
	}	
	Iterator iter = begin;
	++iter;
	for(; iter != end; ++iter, ++begin){
		if(less_than(*iter, *begin)){
			return false;
		}
	}
	return true;
}

template <typename ElementType, typename LessThanFunctor>
void insertion_sort(std::vector<ElementType> &v, LessThanFunctor less_than){
	int test = 0;
	for(int k = 1; k < v.size(); ++k){
		//std::cout << std::endl;
		ElementType current = v[k];
		int j = k;
		while(j > 0){
			//std::cout << ++test << std::endl;
			if(less_than(current, v[j - 1])){							// using the code to sort provided, not much explanation needed
				v[j] = v[j - 1];
			}else{
				//std::cout << "Whimp" << std::endl;
				break;
			}
			--j;
		}
		v[j] = current;
	}
}

template <typename Iterator, typename LessThanFunctor>
void insertion_sort(Iterator begin, Iterator end, LessThanFunctor less_than){
	for(auto k = begin; k < end; ++k){
		auto current = *k;									// starting to understand the pointers and passing refferences part 
		auto j = k;											// took me a while to figure out to pass the id of the iterators
		while(j > begin - 1){								// and use that in the exact same way as if I were using a vector
			if(less_than(current, *(j - 1))){				// only difference is: vectors the "j"'s are in square parenthasies
				*j = *(j - 1);								// and here they are refferences to the original vector.
			}else{											
				break;
			}
			--j;
		}
		*j = current;										// wow this took me far longer than it should have, granted... the solution was not 
	}														// obvious like the past few assignments offered but looking at this it basically is
}															// copy paste from the other parts... *sigh*


template <typename T>
void assignment1(std::vector<T> v){
	std::vector<T> newV1 = v;														// this is the dumbest function but... I guess it gets the job done
	std::vector<T> newV2 = v;
	insertion_sort(newV1, [](auto i, auto j){return i < j;});
	insertion_sort(newV2.begin(), newV2.end(), [](auto i, auto j){return i < j;});
	std::sort(v.begin(), v.end());
	assert(check_sorted(v, [](auto i, auto j){return i < j;}));
	assert(check_sorted(v.begin(), v.end(), [](auto i, auto j){return i < j;}));
	assert(newV1 == v);
	assert(newV2 == v);
	std::random_shuffle(v.begin(), v.end());
	newV1 = v;
	newV2 = v;
	if(v.size() > 3){assert(!check_sorted(v, [](auto i, auto j){return i < j;}));}					// if the vector has less than 3 elements the vector
	if(v.size() > 3){assert(!check_sorted(v.begin(), v.end(), [](auto i, auto j){return i < j;}));}	// refuses to be shuffled aka I needed the if here to
	std::sort(v.begin(), v.end());																	// continue having the stupid assert
	insertion_sort(newV1, [](auto i, auto j){return i < j;});
	insertion_sort(newV2.begin(), newV2.end(), [](auto i, auto j){return i < j;});
	assert(newV1 == v);
	assert(newV2 == v);
}

int main(){
	std::vector<char> charactersEmpty = {};
	std::vector<char> charactersFull = {'a', 'g', 'f', 't'};
	std::vector<double> doublesEmpty = {};
	std::vector<double> doublesFull = {1.53, 54.645, 464.43};
	std::vector<double> variableVector(10);
	int j = variableVector.size();
	for(auto i = 0; i < variableVector.size(); ++i){
		variableVector[i] = j;
		--j;
	}
	assignment1(charactersEmpty);
	assignment1(charactersFull);
	assignment1(doublesEmpty);
	assignment1(doublesFull);
	insertion_sort(variableVector, [](auto i, auto j){return i < j;});
}