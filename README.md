# Snake Game

## Giới thiệu

**Snake Game** là một trò chơi kinh điển được phát triển bằng ngôn ngữ lập trình C++ với việc sử dụng thư viện đồ họa **SFML** để xây dựng giao diện người dùng trực quan. Dự án được thiết kế nhằm tái hiện lại trò chơi rắn săn mồi nổi tiếng với những tính năng cơ bản như: di chuyển rắn, sinh thức ăn ngẫu nhiên, tăng điểm và chiều dài khi ăn thức ăn, đồng thời kiểm tra va chạm để kết thúc trò chơi. Trò chơi được xây dựng dựa trên các nguyên tắc lập trình hướng đối tượng, tận dụng cấu trúc code rõ ràng và các công cụ quản lý phiên bản như GitHub để đảm bảo tính ổn định và dễ mở rộng.

## Demo

*Dưới đây là một hình ảnh hoặc GIF mô tả trò chơi (chụp màn hình trò chơi khi rắn di chuyển, ăn thức ăn và hiển thị điểm số).*

(update demo video cho nay nhaa)

## Cách chạy game

### Cài đặt các dependences và thực thi 

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

(tom tat huong dan choi game o day, tom tat thui nhe)

## Kỹ thuật sử dụng trong game

(tom tat ky thuat su dung trong game tai day)

Dưới đây là phần bổ sung giải thích cấu trúc thư mục cho tệp README của bạn:

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
