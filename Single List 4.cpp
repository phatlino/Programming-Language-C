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
void SList<data>show()
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









