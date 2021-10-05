/* Danh sách liên kết đơn : Single List
- Sử dụng "template <class ...>" : cho phép bạn cài đặt, sử dụng với mọi kiểu dữ liệu : int, double, char, ...
- Sử dụng "class" thay vì "struct" : nếu bạn chưa học HƯỚNG ĐỐI TƯỢNG thì không cần lo, cách cài đặt sẽ không khác mấy với "struct"
- Cài đặt một số hàm cơ bản về danh sách liên kết đơn : khởi tạo, thêm nút, xóa nút, tìm kiếm nút, ...
*/

#include<iostream>

//Khai báo prototype ở đầu chương trình
template <class data> class node;        //Lớp nút đơn
template <class data> class SList;       //Lớp danh sách liên kết đơn

//====================================================================================================
template <class data>       //data : là một kiểu dữ liệu mà bạn muốn sử dụng : int, double, char, ...
class node{
  public:       //Cho phép truy cập từ bên ngoài lớp
    data info;      //Kiểu dữ liệu của nút
    node* next;     //Thành phần truy cập đến nút tiếp theo
 
  //Dưới đây : mỗi hàm sẽ được cài đặt ở các bài riêng theo thứ tự  
  
  //HÀM KHỞI TẠO : không có kiểu trả về, tên hàm trùng với tên lớp
  node(data value = 0);         //Mặc định là 0 nếu không thêm tham số
  
  /*Cách khai báo
  node<int> a;                    //Hoặc node<int> a(5);
  node<char> a;                   //Hoặc node<char> a('a');
  node<int>* p = new node<int>;   //Hoặc node<int>* p = new node<int>(5);
  
  Khi sử dụng "struct", khai báo một biến node : node a;
  - Bạn phải làm thêm một việc đó là gán giá trị cho nút và gán con trỏ next của nút đó bằng NULL
  
  Đối với sử dụng "class", khai báo một biến node : node a(5);
  - Nút a đã có giá trị là 5 và con trỏ next của nó đã bằng NULL
  - Bạn sẽ không cần phải lăn tăn việc đã gán giá trị cho nó chưa, giảm bớt nhiều thao tác, tránh lỗi khi sử dụng*/
    
  //HÀM BỔ TRỢ : có kiểu trả về
  void change(data value);        //Thay đổi lại giá trị của nút
};

template <class data>             //Khởi tạo nút
node<data>::node(data value)
{
  info = value;
  next = NULL;
}

template <class data>             //Thay đổi lại giá trị của nút
void node<data>::change(data value)
{
  info = value;
}
//====================================================================================================
template <class data>
class SList{
  public:
    node<data>* head, * tail;           //Con trỏ đầu và con trỏ cuối của danh sách
    int len;                            //Độ dài của Single List
    
  //HÀM KHỞI TẠO
  SList();                              //Khởi tạo danh sách rỗng
  //NÂNG CAO
  SList(int length, ...);               //Khởi tạo danh sách có sẵn các nút
  
  //HÀM BỔ TRỢ : được viết ở các bài sau
  void addhead(data element);           //Thêm vào đầu danh sách    O(1)
  void addhead(node<data>* element);    //Thêm vào đầu danh sách    O(1)
  void addtail(data element);           //Thêm vào cuối danh sách   O(1)
  void addtail(node<data>* element);    //Thêm vào cuối danh sách   O(1)
  void addbet(node<data>* p, data element, bool before = true);            //before = true : thêm vào trước p - before = false : them vào sau p   O(1) hoặc O(n)
  void addbet(node<data>* p, node<data>* element, bool before = true);     //before = true : thêm vào trước p - before = false : them vào sau p   O(1) hoặc O(n)
  
  void delhead();                       //Xóa phần tử đầu           O(1)
  void deltail();                       //Xóa phần tử cuối          O(1)
  void delnode(node<data>* element)     //Xóa nút element           O(1) hoặc O(n)
  
  node<data>* max();                    //Trả về nút lớn nhất - danh sách rỗng thì trả về NULL                                  O(n)
  node<data>* min();                    //Trả về nút nhỏ nhất - danh sách rỗng thì trả về NULL                                  O(n)
  node<data>* find(data element);       //Tìm nút mang giá trị element - danh sách rỗng hoặc không tìm thấy thì trả về NULL     O(n)
  
  void sort_interchange();              //Sắp xếp danh sách : dùng Interchange Sort     O(n^2)
  void sort_buble();                    //Sắp xếp danh sách : dùng Buble Sort           O(n^2)
  void sort_insertion();                //Sắp xếp danh sách : dùng Insertion Sort       O(n^2)
  void sort_selection();                //Sắp xếp danh sách : dùng Selection Sort       O(n^2)
  
  void reverse();                       //Đảo danh sách             O(n)
};

template <class data>                   //Khởi tạo danh sách rỗng
SList<data>::SList()
{
  head = tail = NULL;
  len = 0;
}

/*NÂNG CAO : thêm thư viện stdarg.h
Tiện lợi cho việc thử nghiệm : khai báo một danh sách có sẵn các nút
Ví dụ : SList<int> list(5, 9, 8, 7, 6, 5);
- Lúc này danh sách liên kết gồm 5 nút : 9 8 7 6 5

Hãy sử dụng hàm này đúng mục đích để tránh các lỗi
Ví dụ sau đây là sử dụng sai mục đích của hàm : SList<int> list(5, 1, 2, 3, 4);
Khai báo số phần tử là 5 nhưng chỉ bỏ vào 4 phần tử, sẽ gây ra giá trị rác

Trường hợp khai báo dư số phần tử sẽ không gây ra lỗi : SList<int> list(3, 1, 2, 3, 4, 5);
*/

#include<stdarg.h>
template <class data>                   //Khởi tạo danh sách có sẵn các nút
SList<data>::SList(int length, ...)
{
  if(length <= 0)
  {
    head = tail = NULL;
    len = 0;
    return;
  }
  
  len = length;           //Gán độ dài của danh sách
  
  va_list list;           //Sử dụng biến va_list trong thư viện stdarg.h để di chuyển qua các biến thuộc dấu '...'
  va_start(list, length); //Trỏ vào biến trước dấu '...'
  
  head = tail = new node<data>(va_arg(list, data));     //Tạo nút đầu tiên mang giá trị của biến đầu tiên trong dấu '...'
  
  for(int i = 1; i < length; i++, tail = tail->next)    //Tạo length - 1 nút còn lại
    tail->next = new node<data>(va_arg(list, data));    //Tạo các node liên tiếp
  
  tail->next = NULL;             //Đặt điểm dừng cho tail
}
