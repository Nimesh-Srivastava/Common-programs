#include <iostream>
using namespace std;

int queue[100], n = 100, front = - 1, rear = - 1;

void Insert() {
   int val;
   if (rear == n - 1)
   cout<<"Queue Overflow"<<endl;
   else {
      if (front == -1)
      front = 0;
      cout<<"Input element : ";
      cin >> val;
      rear++;
      queue[rear] = val;
   }
}
void Delete() {
   if (front == -1 || front > rear) {
      cout<<"Queue Underflow ";
      return ;
   } else {
      cout<<"\nElement deleted from queue is : "<< queue[front] << endl;
      front++;;
   }
}
void Display() {
	if (front == -1)
	cout<<"Queue is empty"<<endl;
	else {
    	cout<<"\nQueue elements are : |START| ";
		for (int i = front; i < rear; i++)
			cout << queue[i] << " -> ";
    	cout << queue[rear] << " |END|" << endl;
   }
}
int main() {
   int ch;
   cout<<"\n1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit";
   do {
      cout<<"\nChoice : ";
      cin>>ch;
      switch (ch) {
         case 1: Insert();
         break;
         case 2: Delete();
         break;
         case 3: Display();
         break;
         case 4: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=4);
   return 0;
}
