# Snake Game

## Giới thiệu

Snake Game là một trò chơi đơn giản được viết bằng ngôn ngữ lập trình C++ sử dụng thư viện SFML cho giao diện đồ họa. Mục tiêu của dự án là xây dựng một phiên bản đơn giản của trò chơi rắn săn mồi nổi tiếng, với các tính năng cơ bản như di chuyển rắn, ăn thức ăn để tăng điểm và chiều dài. 

## Demo

https://github.com/user-attachments/assets/7b27b798-902e-4a7b-9c14-66d345440c8f

## Cách chạy game

### Cách 1: Cài đặt các dependences và thực thi 

#### 1. Cài đặt thư viện SFML

Để chạy dự án này, bạn cần cài đặt **SFML**. Thực hiện các bước sau tùy theo hệ điều hành của bạn:

- **Linux (Ubuntu)**:
  ```bash
  sudo apt-get install libsfml-dev
  ```

- **macOS** (sử dụng Homebrew):
  ```bash
  brew install sfml
  ```

- **Windows**:
  - Tải SFML từ [https://www.sfml-dev.org/download.php](https://www.sfml-dev.org/download.php) và làm theo hướng dẫn cài đặt cho Windows.
  - Thêm thư mục `SFML\bin` vào biến môi trường PATH để có thể sử dụng SFML trong dòng lệnh.

#### 2. Clone source code

```bash
git clone https://github.com/Healer-H/SnakeGame.git
cd SnakeGame 
```

#### 3. Biên dịch và chạy trò chơi

Nếu bạn đã cài đặt SFML, bạn có thể biên dịch và chạy trò chơi theo một trong các cách sau:

##### Sử dụng Makefile (Linux/macOS)
1. Trong thư mục SnakeGame, chạy lệnh:
   ```bash
   make
   ```
2. Sau khi biên dịch, chạy trò chơi bằng lệnh:
   ```bash
   ./snake_game
   ```

##### Sử dụng Visual Studio (Windows)
1. Mở dự án trong Visual Studio.
2. Cấu hình đường dẫn tới thư viện SFML trong Properties > VC++ Directories.
3. Biên dịch và chạy dự án bằng cách nhấn `Ctrl + F5`.

## Hướng dẫn chơi game
### Mục tiêu trò chơi

- Điều khiển rắn để ăn thức ăn, tăng điểm và chiều dài.
- Tránh để đầu rắn va vào thân.
### Cách điều khiển

- ⬆️ Di chuyển rắn lên phía trên.
- ⬇️ Di chuyển rắn xuống phía dưới.
- ⬅️ Di chuyển rắn sang bên trái.
- ➡️ Di chuyển rắn sang bên phải.

### Quy tắc trò chơi

- Rắn sẽ dài hơn sau mỗi lần ăn thức ăn.
- Trò chơi kết thúc nếu đầu rắn chạm vào thân của chính nó.

### Mẹo chơi

- Tận dụng khả năng xuyên qua cạnh đi ra từ phía đối diện để tối ưu hóa đường đi.
- Tránh khu vực hẹp để không bị chặn đường di chuyển.
- Ăn liên tục 5 thức ăn để tạo ra bigger-food, giúp ghi nhiều điểm hơn (Tính năng đang phát triển).

### Hướng dẫn cách chơi game chi tiết tại [đây](https://github.com/Healer-H/SnakeGame/blob/master/docs/user_guide.md)

---

## Cấu trúc thư mục

Dự án game Snake được tổ chức thành các thư mục và tệp như sau:

```
SnakeGame/
├── src/                     # Chứa mã nguồn chính của trò chơi
│   ├── main.cpp             # Tệp main bắt đầu trò chơi
│   ├── Game.h / Game.cpp    # Định nghĩa và thực thi lớp Game, quản lý vòng lặp trò chơi
│   ├── Snake.h / Snake.cpp  # Định nghĩa và thực thi lớp Snake, quản lý các hoạt động của rắn
│   ├── Food.h / Food.cpp    # Định nghĩa và thực thi lớp Food, sinh và vẽ thức ăn
│   ├── UI.h / UI.cpp        # Định nghĩa và thực thi lớp UI, hiển thị điểm số và thông báo
├── assets/                  # Thư mục chứa tài nguyên trò chơi
│   └── .gitkeep             # Tệp giữ chỗ để đảm bảo thư mục được lưu trong Git
├── docs/                    # Thư mục chứa tài liệu dự án
│   ├── user_guide.md        # Hướng dẫn chi tiết cách chơi trò chơi
│   ├── technical_docs.md    # Tài liệu kỹ thuật chi tiết về các lớp và thuật toán trong trò chơi
├── build/                   # Thư mục chứa các tệp biên dịch và tệp tạm thời
│   └── .gitkeep
├── README.md                # Tệp README, mô tả dự án và hướng dẫn sử dụng
└── .gitignore               # Tệp .gitignore để loại trừ các tệp không cần thiết khỏi Git
```
