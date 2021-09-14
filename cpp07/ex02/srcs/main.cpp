#include "Array.tpp"

int main()
{
	Array<double>   arr_1;
	Array<float>    arr_2(4);
	Array<int>    	arr_3(5);
	Array<int>    	arr_4(2);

	std::cout << "size 1: " << arr_1.size() << std::endl;
	std::cout << arr_1 << std::endl << std::endl;
	std::cout << "size 2: " << arr_2.size() << std::endl;
	std::cout << arr_2 << std::endl << std::endl;
	std::cout << "size 3: " << arr_3.size() << std::endl;
	std::cout << arr_3 << std::endl;
	
	arr_3[3] = 5;
	std::cout << arr_3 << std::endl;
	try
	{
		std::cout << "arr_3[7] = " << arr_3[7] << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	arr_4 = arr_3;
	arr_4[1] = 2;
	std::cout << "size 4: " << arr_3.size() << std::endl;
	std::cout << arr_4 << std::endl << std::endl;
	Array<int>   arr_5(arr_4);
	std::cout << "size 5: " << arr_3.size() << std::endl;
	std::cout << arr_5 << std::endl;
	return 0;
}