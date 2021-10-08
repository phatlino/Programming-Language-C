/*Bài này bao gồm các hàm
- Xóa nút đầu của danh sách
- Xóa nút cuối của danh sách
- Xóa một nút được chỉ định
- Tìm nút mang giá trị lớn nhất
- Tìm nút mang giá trị nhỏ nhất
- Tìm nút mang giá trị được chỉ định
*/

//Lưu ý : hãy chắc chắn rằng bạn không làm sai giá trị của biến len so với độ dài của danh sách, nếu không sẽ dễ gây ra lỗi

//Xóa nút đầu
template <class data>
void SList<data>::delhead()
{
  if(head == NULL)
    return;
  
  if(len == 1)
  {
    delete head;
    head = tail = NULL;
    len = 0;
    return;
  }
  
  node<data>* p = head;
  head = head->next;
  delete p;
  len--;
}

//Xóa nút cuối
template <class data>
void SList<data>::deltail()
{
  if(head == NULL)
    return;
  
  if(len == 1)
  {
    delete tail;
    head = tail = NULL;
    len = 0;
    return;
  }
  
  //Tìm đến nút trước tail
  for(node<data>* i = head; i->next; i = i->next)
    if(i->next == tail)
    {
      i->next = NULL;
      delete tail;
      tail = i;
      break;
    }
  len--;
}

/*GIẢI THUẬT : xóa một nút element trong danh sách
Ta có danh sách list gồm các nút : 5 2 7 8 NULL

Xóa nút element mang giá trị bằng 2
  Bước 1 : gán giá trị nút sau nút element vào chính nó, ta được danh sách mới : 5 7 7 8 NULL
  Bước 2 : xóa một nút sau nút element, ta được danh sách mới                  : 5 7 8 NULL
  
TRƯỜNG HỢP nút element là nút cuối : độ phức tạp O(n)
=> Độ phức tạp của việc xóa một nút element là O(1) hoặc O(n)
*/

//Xóa nút được chỉ định
template <class data>
void SList<data>::delnode(node<data>* element)
{
  if(head == NULL || element == NULL)
    return;
  
  if(len == 1)
  {
    delete head;
    head = tail = NULL;
    len = 0;
    return;
  }
  
  if(element != tail)
  {
    node<data>* p = element->next;      //p là nút sau nút element
    if(tail == p)
      tail == element;
    
    element->info = p->info;            //Đưa giá trị của nút p lên nút element
    element->next = p->next;            //Loại nút p khỏi danh sách
    delete p;                           //Giải phóng nút p
    len--;
    return;
  }
  
  //Trường hợp element == tail
  for(node<data>* i = head; i->next; i = i->next)
    if(i->next == tail)
    {
      i->next = NULL;
      delete tail;
      tail = i;
      break;
    }
  len--;
}

//Tìm nút mang giá trị lớn nhất
template <class data>
node<data>* SList<data>::max()
{
  if(head == NULL)
    return NULL;
  
  node<data>* node_max = head;
  
  for(node<data>* i = head->next; i; i = i->next)
    if(node_max->info < i->info)
      node_max = i;
  return node_max;
}

//Tìm nút mang giá trị nhỏ nhất
template <class data>
node<data>* SList<data>::min()
{
  if(head == NULL)
    return NULL;
  
  node<data>* node_min = head;
  
  for(node<data>* i = head->next; i; i = i->next)
    if(node_min->info > i->info)
      node_min = i;
  return node_min;
}

//Tìm nút mang giá trị element được chỉ định
template <class data>
node<data>* SList<data>::find(data element)
{
  if(head == NULL)
    return NULL;
  
  for(node<data>* i = head; i; i = i->next)
    if(i->info == element)
      return i;
  return NULL;
}
