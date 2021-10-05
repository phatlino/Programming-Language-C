/* Danh sách liên kết đơn : Linked List
- Sử dụng "template <class ...>" : cho phép bạn cài đặt, sử dụng với mọi kiểu dữ liệu : int, double, char, ...
- Sử dụng "class" thay vì "struct" : nếu bạn chưa học HƯỚNG ĐỐI TƯỢNG thì không cần lo, cách cài đặt sẽ không khác mấy với "struct"
- Cài đặt một số hàm cơ bản về danh sách liên kết đơn : khởi tạo, thêm nút, xóa nút, tìm kiếm nút, ...
*/

//Khai báo prototype ở đầu chương trình
template <class data> class node;        //Lớp nút đơn
template <class data> class Slist;       //Lớp danh sách liên kết đơn

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
  - Bạn sẽ không cần phải lăn tăn việc đã gán giá trị cho nó chưa, giảm bớt nhiều thao tác khi sử dụng
  */
    
  //HÀM BỔ TRỢ : có kiểu trả về
}
