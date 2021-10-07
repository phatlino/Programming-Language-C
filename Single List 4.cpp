/*Bài này bao gồm các hàm
- Kiểm tra danh sách rỗng
- Xuât danh sách
- Xuất danh sách theo chiều ngược
- Giải phóng toàn bộ danh sách
- Đảo danh sách
- Kiểm tra danh sách có đối xứng
*/

template <class data>
bool SList<data>::isEmpty()
{
  return head == NULL;
}

template <class data>
void SList<data>::show()
{
  for(node<data>* i = head; i; i = i->next)
    std::cout << i->info << " ";
  std::cout << "NULL\n";
}

/*Danh sách liên kết đơn không thể đi từ chiều ngược lại được
Vì vậy ta cần sử dụng kỹ thuật đệ quy để giải quyết bài toán xuất ngược danh sách
*/

//Hàm xuất ngược danh sách liên kết đơn như sau, hàm này không thuộc lớp SList

template <class data>
void SList_showrev(node<data>* head)      //Nhận vào một con trỏ head
{
  if(head == NULL)
    return;
    
  SList_showrev(head->next);        //Đệ quy
  std::cout << " " << head->info;
}

//Sử dụng hàm trên để in ngược danh sách
template <class data>
void SList<data>::showrev()
{
  std::cout << "NULL";
  SList_showrev(head);
  std::cout << '\n';
}

//Hàm giải phóng toàn bộ danh sách

template <class data>
void SList<data>::del()
{
  if(head == NULL)
    return;
  
  for(node<data>* i = head; i; i = head)
  {
    head = head->next;
    delete i;
  }
  tail = NULL;
  len = 0;
}

//Ta có thể dùng đệ quy để giải phóng các nút theo chiều ngược, hàm dưới đây sẽ được đóng lại bằng các dấu //

/*Cần sử dụng một hàm phụ, hàm này không thuộc lớp SList
template <class data>
void SList_del(node<data>* head)      //Nhận vào một nút head
{
  if(head == NULL)
    return;
    
  SList_del(head->next);        //Đệ quy
  delete head;                  //Giải phóng
}

template <class data>
void SList<data>::del()
{
  SList_del(head);      //Gọi hàm giải phóng danh sách
  head = tail = NULL;
  len = 0;
}
*/

//Hàm đảo danh sách

template <class data>
void SList<data>::reverse()
{
  if(len <= 1)
    return;
  
  node<data>* p = tail = head;
  head = head->next;
  tail->next = NULL;
  
  for(node<data>* i = head; i; i = head)
  {
    head = head->next;
    i->next = p;
    p = i;
  }
  
  head = p;
}

/*Tạo một SList cùng kiểu rỗng
Ta đẩy lần lượt giá trị của từng nút theo chiều xuôi vào đầu danh sách mới này
Sau đó duyệt qua từng nút của hai danh sách và so sánh chúng
*/

//Hàm kiểm tra danh sách đối xứng

template <class data>
bool SList<data>::isSymmetry()
{
  SList<data> list;
  for(node<data>* i = head; i; i = i->next)     //Đẩy từng giá trị vào đầu danh sách mới
    list.addhead(i->info);
  
  for(node<data>* i = head, * j = list.head; i; i = i->next, j = j->next)
    if(i->info != j->info)
    {
      list.del();       //Giải phóng danh sách mới
      return false;     //Danh sách không đối xứng
    }
  
  list.del();           //Giải phóng danh sách mới
  return true;          //Danh sách đối xứng
}
