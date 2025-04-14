let students = [];

let editingIndex = -1;

// Render danh sách sinh viên
function renderTable(students) {
  const tableBody = document.getElementById("tbody");
  tableBody.innerHTML = "";

  students.forEach((student, index) => {
    const row = `
        <tr>
          <td>${student.name}</td>
          <td>${student.id}</td>
          <td>${student.email}</td>
          <td>${student.class}</td>
          <td>
            <button class="edit-btn" onclick="editStudent(${index})">Sửa</button>
            <button class="delete-btn" onclick="deleteStudent(${index})">Xoá</button>
          </td>
        </tr>
      `;
    tableBody.innerHTML += row;
  });
}

// Hiển thị danh sách ban đầu
renderTable(students)

// kiểm tra thông tin nhập vào
function validateForm(name, id, email, className) {
  let valid = true;

  document.getElementById("name-error").textContent = name ? "" : "Họ tên không được để trống!";
  document.getElementById("id-error").textContent = id ? "" : "MSSV không được để trống!";
  document.getElementById("email-error").textContent = email.includes("@") ? "" : "Email không hợp lệ!";
  document.getElementById("class-error").textContent = className ? "" : "Lớp không được để trống!";

  if (!name || !id || !email.includes("@") || !className) {
    valid = false;
  }

  return valid;
}

// Xử lý thêm hoặc cập nhật sinh viên
document.getElementById("submit-btn").addEventListener("click", () => {
  const name = document.getElementById("name").value.trim();
  const id = document.getElementById("student-id").value.trim();
  const email = document.getElementById("email").value.trim();
  const className = document.getElementById("class").value.trim();

  if (!validateForm(name, id, email, className)) return;

  const newStudent = { name, id, email, class: className };

  if (editingIndex === -1) {
    // Thêm mới
    students.push(newStudent);
  } else {
    // Cập nhật
    students[editingIndex] = newStudent;
    editingIndex = -1;
    alert("Sửa thông tin thành công")
  }

  renderTable(students);
  document.getElementById("student-form").reset();
});

// Sửa sinh viên
function editStudent(index) {
  const student = students[index];
  document.getElementById("name").value = student.name;
  document.getElementById("student-id").value = student.id;
  document.getElementById("email").value = student.email;
  document.getElementById("class").value = student.class;

  editingIndex = index;
  document.getElementById("submit-btn").textContent = "Cập nhật";
}

// Xoá sinh viên
function deleteStudent(index) {
  if (confirm("Bạn có chắc muốn xoá sinh viên này?")) {
    students = students.filter((_, i) => i !== index);
    renderTable(students);
  }
}

// Tìm kiếm theo tên
document.getElementById("search").addEventListener("input", (e) => {
  const keyword = e.target.value.toLowerCase();
  const filtered = students.filter(student =>
    student.name.toLowerCase().includes(keyword)
  );
  renderTable(filtered);
});
