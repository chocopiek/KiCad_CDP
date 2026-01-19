❗ ĐỌC KỸ – VI PHẠM LÀ HỎNG PROJECT
❌ Không 2 người cùng sửa 1 file
Đặc biệt: *.kicad_pcb
❌ Không commit khi đang mở KiCad
✅ Mỗi người làm trên branch riêng
✅ Trước khi làm gì → luôn git pull

**CÀI ĐẶT (LÀM 1 LẦN)**

Cài Git https://git-scm.com

Mở Git Bash (chuột phải vào file rồi chạy cmd ở file đó)

Set tên và email:
git config --global user.name "Ten Cua Ban"
git config --global user.email "email@gmail.com"

**LẦN ĐẦU THAM GIA PROJECT**
**Bước 1:** Clone project về máy
git clone https://github.com/USERNAME/CDP-Final.git
cd CDP-Final
**Bước 2:** Tạo branch RIÊNG cho mình
git checkout -b tenban-schematic
(thay tenban thành tên m)

4. QUY TRÌNH LÀM VIỆC MỖI NGÀY (RẤT QUAN TRỌNG)
Bước 1: Cập nhật code mới nhất
git pull origin main

Bước 2: Mở KiCad và chỉnh sửa phần của mình
Chỉ sửa file được phân công
Không đụng file người khác

Bước 3: Kiểm tra file đã thay đổi
git status

Bước 4: Thêm file vào commit
git add .
**(đụ má nhớ tắt KiCad nha mấy cha)**
(commit rõ ràg đã sửa những gì)

Bước 5: Push lên GitHub
git push origin tenban-schematic

MERGE VÀO MAIN (KHÔNG TỰ Ý)
❌ KHÔNG ai tự merge vào main

Cách đúng:
Lên GitHub
Tạo Pull Request
Leader review
Leader merge
