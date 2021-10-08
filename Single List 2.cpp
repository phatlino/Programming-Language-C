/*Bài này bao gồm các hàm sau
- Thêm một nút vào head : có thể gọi giá trị hoặc một nút có sẵn
- Thêm một nút vào tail : có thể gọi giá trị hoặc một nút có sẵn
- Thêm một nút vào trước, sau nút chỉ định*/

//Tên hàm trùng nhau nhưng khi sử dụng bạn đưa vào giá trị hay một nút thì nó sẽ hiểu

//Hàm thêm vào đầu danh sách : tham số là một giá trị
template <class data>
void SList<data>::addhead(data element)
{
  node<data>* p = new node<data>(element);      //p->next đã bằng NULL
  
  if(head == NULL)
    head = tail = p;
  else{
    p->next = head;
    head = p;
  }
  
  len++;
}

//Hàm thêm vào đầu danh sách : tham số là nút có sẵn
template <class data>
void SList<data>::addhead(node<data>* element)
{
  if(element == NULL)
    return;
  
  if(head == NULL)
  {
    head = tail = element;
    element->next = NULL;
  }else{
    element->next = head;
    head = element;
  }
  
  len++;
}

template <class data>
void SList<data>::addtail(data element)
{
  node<data>* p = new node<data>(element);      //p->next đã bằng NULL
  
  if(head == NULL)
    head = tail = p;
  else{
    tail->next = p;
    tail = p;
  }
  len++;
}

template <class data>
void SList<data>::addtail(node<data>* element)   //element->next chưa chắc đã bằng NULL
{
  if(element == NULL)
    return;
  
  if(head == NULL)
    head = tail = element;
  else{
    tail->next = element;
    tail = element;
  }
  
  element->next = NULL;
  len++;
}

//Hàm hoán vị
template <class data>
void swap(data &a, data& b)
{
  data temp = a;
  a = b;
  b = temp;
}

/*Quay lại bài Single List 1 : khai báo prototype hai hàm addbet thì đã gán giá trị bool before = true
Nên khi gọi lại hàm này, ta không cần gán lại giá trị này nữa

Nhắc lại kiến thức : before = true thì thêm một nút vào trước nút p, before = false thì thêm một nút vào sau nút p

Cách gọi hàm : ta có sẵn một SList<int> list;
- Nếu thêm một nút vào trước nút p thì : list.addhead(p, 10);         //Thêm một nút mang giá trị 10 vào trước nút p
- Nếu thêm một nút vào sau nút p thì   : list.addhead(p, 10, false);  //Thêm một nút mang giá trị 10 vào sau nút p

GIẢI THUẬT :
* Thêm một nút vào trước nút p
  - Ta có một danh sách list gồm các nút : 5 2 3 7 NULL
  
  Nút p mang giá trị 2, ta cần thêm một nút k mang giá trị 1 vào trước p
  Bước 1 : thêm nút k vào sau nút p, ta được danh sách mới           : 5 2 1 3 7 NULL
  Bước 2 : hoán vị giá trị của hai nút p và k, ta được danh sách mới : 5 1 2 3 7 NULL
  
  TRƯỜNG HỢP p = NULL : bạn có thể không thêm nút vào và đóng hàm đi, nhưng ở đây mình sẽ thêm vào cuối danh sách. Việc này do người viết tự định nghĩa
  => Độ phức tạp của việc thêm một nút vào trước nút p luôn là O(1)
  
* Thêm một nút vào sau nút p
  - Ta có một danh sách list gồm các nút : 5 2 3 7 NULL
  Nút p mang giá trị 2, ta cần thêm một nút k mang giá trị 1 vào sau p
  Bước 1 : thêm nút k vào sau nút p, ta được danh sách mới           : 5 2 1 3 7 NULL
  
  TRƯỜNG HỢP p = NULL : mình sẽ không thêm nút vào và đóng hàm lại
  => Độ phức tạp của việc thêm một nút vào sau nút p luôn là O(1)
  
Vì vậy hàm addbet luôn là thêm vào sau nút p, chỉ hoán vị khi before = true*/

template <class data>
void SList<data>::addbet(node<data>* p, data element, bool before)
{
  if(head == NULL || p == NULL && !before)
    return;
  
  //Nút p = NULL thì sẽ thêm một nút vào cuối
  if(p == NULL)
  {
    addtail(element);
    return;
  }
  
  node<data>* k = new node<data>(element);
  
  //Thêm nút k vào sau p
  k->next = p->next;
  p->next = k;
  
  //Hoán vị hai nút p, k khi before = true
  if(before && p->info != k->info)
    swap(p->info, k->info);
  
  //Gán lại tail nếu tail trùng p
  if(tail == p)
    tail = k;
  len++;
}

template <class data>
void SList<data>::addbet(node<data>* p, node<data>* element, bool before)
{
  if(head == NULL || element == NULL || p == NULL && !before)
    return;
  
  //Nút p = NULL thì sẽ thêm một nút vào cuối
  if(p == NULL)
  {
    addtail(element);
    return;
  }
  
  element->next = p->next;
  p->next = element;
  
  //Hoán vị hai nút p, element khi before = true
  if(before && p->info != element->info)
    swap(p->info, element->info);
  
  //Gán lại tail nếu tail trùng p
  if(tail == p)
    tail = element;
  len++;
}
