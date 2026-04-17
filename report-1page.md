# Báo cáo Lab 2 - Classical Ciphers

## 1. Caesar Cipher

**Mô tả**: Caesar Cipher là mã thay thế đơn giản, mỗi ký tự được dịch chuyển theo một khóa cố định. Chương trình hỗ trợ chữ hoa, chữ thường và giữ nguyên các ký tự không phải chữ (dấu cách, dấu câu...).

**Hàm chính**:
- `caesar_encrypt()`
- `caesar_decrypt()`

**Kết quả test**:
- Input: `I LOVE YOU`, key = 3 → `L ORYH BRX`
- Decrypt thành công về bản gốc.
- Test với dấu cách và ký tự đặc biệt hoạt động tốt.

## 2. Rail Fence Cipher

**Mô tả**: Rail Fence là mã hoán vị, viết văn bản theo kiểu zigzag theo số đường ray (rails), sau đó đọc theo hàng ngang.

**Hàm chính**:
- `railFenceEncrypt()`
- `rail_fence_decrypt()`
- `read_message_from_file()` (Q8)

**Kết quả test**:
- "I LOVE YOU" với 3 rails → mã hóa và giải mã thành công.
- Test với 2 rails và 4 rails.
- Input không hợp lệ (rails < 2) → trả về nguyên văn bản.
- Đọc từ `data/input.txt` và mã hóa thành công.

## 3. Khó khăn & Giải pháp
- Ban đầu hàm decrypt Rail Fence bị sai logic vị trí zigzag → đã sửa bằng cách lưu vị trí trước rồi điền ciphertext.
- Phải giữ nguyên dấu cách theo yêu cầu lab.
- Đảm bảo tên hàm đúng theo checker (`rail_fence_decrypt`, `read_message_from_file`, `caesar_decrypt`).

## 4. Kết luận
Đã hoàn thành đầy đủ các yêu cầu Q1-Q8 của bài lab. Chương trình biên dịch và chạy đúng, test cases đạt yêu cầu.

**Ngày hoàn thành**: 17/04/2026
