int main(void) {
	int age = 21; //declare “age” and set it to 21
	bool canDrive; //make a bool to make sure they can drive
    //notice how it is not initialized because we don’t need to yet
	
    if(age >= 16) {
	    canDrive = true;
    } 
    else {
        canDrive = false;
    }
	
    return 0;
}
