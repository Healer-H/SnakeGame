# Tổ chức thư mục dự án
Để thuận tiện cho việc quản lý, bảo trì và phát triển, dự án được tổ chức với cấu trúc thư mục như
sau:
SnakeGame/
    src/ # Chứa mã nguồn chính
        main.cpp *# Điểm bắt đầu của trò chơi*
        Game.h / Game.cpp *# Lớp Game: Quản lý vòng lặp game, xử lý đầu vào, cập nhật trạng thái*
        Snake.h / Snake.cpp *# Lớp Snake: Điều khiển rắn di chuyển, kiểm tra va chạm, và tăng chiều dài*
        Food.h / Food.cpp *# Lớp Food: Tạo thức ăn ngẫu nhiên, kiểm tra vị trí*
        UI.h / UI.cpp *# Lớp UI: hiển thị giao diện*
    assets/ *# Lưu trữ tài nguyên như hình ảnh, âm thanh*
    docs/ *# Tài liệu dự án*
        technical_docs.md *# Tài liệu kỹ thuật*
        user_guide.md *# Hướng dẫn chơi game*
    .gitignore
    Dockerfile *# Cấu hình Docker để chạy game*
    Makefile *# Cấu hình Makefile để biên dịch*
    README.md *# Tóm tắt dự án và hướng dẫn*

# Chức năng chính của trò chơi
• **Di chuyển rắn (Snake Movement):** Rắn được điều khiển bởi các phím mũi tên (Up, Down,
Left, Right).
• **Sinh thức ăn ngẫu nhiên (Food Spawning):** Thức ăn được sinh ngẫu nhiên tại các vị trí
trên màn hình.
• **Kết thúc trò chơi (Game Over):** Trò chơi kết thúc khi đầu rắn cắn vào thân rắn.