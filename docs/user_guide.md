# Giới thiệu và hướng dẫn chơi game

## Giới thiệu chung
**Rắn Săn Mồi (Snake Game)** là một trò chơi đơn giản, được viết trên ngôn ngữ lập trình C++, sử dụng thư viện SFML để xây dựng giao diện để người chơi điều khiển rắn với mục tiêu:
- **Ăn thức ăn:** Ghi điểm và tăng chiều dài rắn.
- **Tránh va chạm:** Cố gắng không để đầu rắn va vào thân, nếu không trò chơi sẽ kết thúc.

---

## Tính năng trò chơi

### Tính năng hiện tại:
- **Thao tác điều khiển chuyển động của rắn:** Rắn được điều khiển bằng các phím mũi tên giúp người chơi dễ dàng thao tác và điều chỉnh hướng di chuyển.
- **Tăng trưởng và ghi điểm:** Mỗi khi rắn ăn thức ăn, điểm số sẽ tăng và chiều dài của rắn cũng tăng lên.
- **Chế độ phản chiếu:** Khi đầu rắn vượt qua biên màn hình, nó sẽ xuất hiện ở phía đối diện.
- **Kết thúc khi rắn cắn vào thân:** Trò chơi sẽ kết thúc nếu đầu rắn chạm vào bất kỳ phần nào của thân rắn.

### Tính năng đang phát triển:
- **Bigger-food:** Một loại thức ăn đặc biệt sẽ xuất hiện khi người chơi ăn liên tục 5 thức ăn bình thường. Bigger-food mang lại lượng điểm số lớn hơn và tạo thêm động lực để người chơi đạt được chuỗi ăn liên tục.
- **Tường và Bản đồ:** Có thể xây dựng thêm các bản đồ khác nhau với địa hình phức tạp hơn. Người chơi nếu va phải địa hình sẽ kết thúc trò chơi.

---

## Cách điều khiển
Người chơi có thể dễ dàng điều khiển rắn di chuyển qua các hướng khác nhau bằng cách sử dụng các phím mũi tên trên bàn phím. Cụ thể:
- ⬆️ Di chuyển rắn lên phía trên.
- ⬇️ Di chuyển rắn xuống phía dưới.
- ⬅️ Di chuyển rắn sang bên trái.
- ➡️ Di chuyển rắn sang bên phải.

---

## Quy tắc và mục tiêu của trò chơi

### Quy tắc
- Rắn di chuyển liên tục, người chơi cần điều chỉnh hướng đi để ăn thức ăn.
- Sau mỗi lần ăn, rắn sẽ tăng chiều dài.
- Nếu đầu rắn chạm vào thân, trò chơi sẽ kết thúc.

### Mục tiêu
- Duy trì trò chơi càng lâu càng tốt bằng cách tránh va chạm.
- Ghi điểm cao nhất bằng cách ăn nhiều thức ăn.

---

## Tải và chạy game

### Cách 1. Cài đặt và chạy trực tiếp
1. **Cài đặt thư viện SFML**  
   Thực hiện các bước sau tùy theo hệ điều hành của bạn:
   - **Linux (Ubuntu):**
     ```bash
     sudo apt-get install libsfml-dev
     ```
   - **macOS (sử dụng Homebrew):**
     ```bash
     brew install sfml
     ```
   - **Windows:**  
     Tải thư viện SFML từ [SFML Download Page](https://www.sfml-dev.org/download.php), cài đặt và cấu hình biến môi trường.

2. **Clone mã nguồn**
   ```bash
   git clone https://github.com/Healer-H/SnakeGame.git
   cd SnakeGame
3. **Build & Run**
    Nếu bạn đã cài đặt SFML, bạn có thể biên dịch và chạy trò chơi theo một trong các cách sau:
-   **Sử dụng Makefile (Linux/macOS)**
    Trong thư mục SnakeGame, chạy lệnh
    ```bash
    make
    ```
    Sau khi biên dịch, chạy trò chơi bằng lệnh
    ```bash
    ./snake_game
    ```
-   **Windows (sử dụng Visual Studio)**
  - Mở dự án trong Visual Studio.
  - Cấu hình thư viện SFML.
  - Biên dịch và chạy bằng `Ctrl + F5`.
### Cách 2. Chạy bằng Docker
1. Cài đặt Docker theo hướng dẫn tại [Docker Documentation](https://docs.docker.com/get-docker/).
2. Clone repository:
    ```bash
    git clone https :// github.com/Healer -H/ SnakeGame .git
    cd SnakeGame
    ```
3. Build Docker Image:
    ```bash
    docker build -t snake_game .
    ```
4. Chạy Docker Container:
    ```bash
    docker run -it --rm snake_game
## Mẹo chơi để ghi điểm cao
- **Tận dụng cạnh màn hình:** Tận dụng khả năng xuyên qua cạnh đi ra từ phía đối diện để tối ưu hóa đường đi, nhanh chóng tiếp cận thức ăn.
- **Quản lý không gian:** Duy trì khoảng cách giữa thân rắn và các khu vực di chuyển hẹp.
- **Chiến lược chuỗi ăn liên tục:** Ăn liên tục 5 thức ăn để tạo ra bigger-food, giúp ghi nhiều điểm hơn. *(Tính năng đang phát triển).*
