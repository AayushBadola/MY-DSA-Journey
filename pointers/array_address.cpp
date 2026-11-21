#include <iostream>
using namespace std;
// for any array say nums[10] = {1,2,3,4,5,6,7,8,9,10}
// if we find the address of "nums" we get the address of the first element of the array that is "1"
// we get this because an array contains only value which are of same type 
// since we can know where the memory block starts for the array (1st element) we can calculate where it ends

/*
for this array "nums" there are 10 elements and an "int" value is of 4 bytes 
so if the nums start at 100 then it will allocate 

100-103 | 104-107| 108 - 111| . . . . . 136-139 

address 100 - byte 1
address 101 - byte 2
address 102 - byte 3
address 103 - byte 4


STANDARD FORMULA IS : END MEMORY = (START location + TOTAL BYTESIZE) -1

so if nums is at 100 and 10 elements are int so 4*10 bytes allocated 
hence 
end memory block = (100 + 40) - 1 = 139 
*/

int main(void){
    int nums[5] = {0,1,2,3,4};
    cout<<"start location of nums: "<<&nums<<endl;
    cout<<"Address of 1st element: "<<&nums[0]<<endl;
    cout<<"Address of last element(starting byte): "<<&nums[4]<<endl;
    cout<<"Value at 1st element: "<<*nums<<endl;
    cout<<"Value at 2nd element: "<<*(nums + 1)<<endl;
    
    // if we write say *(nums) + 1 it will do the MATHEMATICAL CALCULATION 
    // it will do basically *nums that is 1st element "0" and MATHEMATICALLY ADD 1 so it become 0 + 1 = 1

    // if we do *(nums + 1) it will go to 1st element address then go to the next element address (since + 1) 
    // then at that address RETURNS the value it holds

    // BASICALLY 
    // nums[index] = *(nums + index) OR index[nums] = *(index + nums)

    // ##################### TRICK ##########################
    // internally the array value calculation is done via nums[index] = *(nums + index)
    // so we can also write index[nums] and it will give same ans as nums[index];
    
}