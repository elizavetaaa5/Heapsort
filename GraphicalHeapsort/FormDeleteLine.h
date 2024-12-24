#pragma once /* #pragma once — это директива препроцессора, которая указывает компилятору включить файл
заголовка только один раз при компиляции файла исходного кода */

// Подключаемые библиотеки
#include <string>

// Подключаемые файлы проекта
#include "DatabaseQueries.h"
#include "ConnectionString.h"

using namespace std; /* Using namespace std в C++ — это директива, которая позволяет использовать
все идентификаторы из пространства имён std без указания префикса std:: */

namespace GraphicalHeapsort {

	// Использованные пространства имен
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FormDeleteLine
	/// </summary>
	public ref class FormDeleteLine : public System::Windows::Forms::Form
	{
	public:
		FormDeleteLine(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormDeleteLine()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button_delete;
	private: System::Windows::Forms::Button^ button_cancel;


	protected:
		// Объявление элементов формы


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;
		/* #pragma region позволяет указать блок кода, который можно развернуть или свернуть при
		использовании функции структурирования редактора Visual Studio */
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormDeleteLine::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_cancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(55, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(417, 46);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите номер строки";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(463, 63);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(247, 38);
			this->textBox1->TabIndex = 1;
			// 
			// button_delete
			// 
			this->button_delete->Location = System::Drawing::Point(605, 195);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(105, 37);
			this->button_delete->TabIndex = 4;
			this->button_delete->Text = L"Удалить";
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &FormDeleteLine::button_yes_Click);
			// 
			// button_cancel
			// 
			this->button_cancel->Location = System::Drawing::Point(731, 195);
			this->button_cancel->Name = L"button_cancel";
			this->button_cancel->Size = System::Drawing::Size(105, 37);
			this->button_cancel->TabIndex = 5;
			this->button_cancel->Text = L"Отмена";
			this->button_cancel->UseVisualStyleBackColor = true;
			this->button_cancel->Click += gcnew System::EventHandler(this, &FormDeleteLine::button_cancel_Click);
			// 
			// FormDeleteLine
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 30);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(842, 227);
			this->Controls->Add(this->button_cancel);
			this->Controls->Add(this->button_delete);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiBold", 10.8F, System::Drawing::FontStyle::Bold));
			this->ForeColor = System::Drawing::SystemColors::MenuText;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximumSize = System::Drawing::Size(866, 291);
			this->MinimumSize = System::Drawing::Size(866, 291);
			this->Name = L"FormDeleteLine";
			this->Text = L"Подтверждение удаления строки";
			this->Load += gcnew System::EventHandler(this, &FormDeleteLine::FormDeleteLine_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		//Директива #pragma endregion помечает конец блока, определённого директивой #pragma region.
#pragma endregion

	/* Обработки событий, которые могут быть вызваны в процессе работы программы */
	private: System::Void button_yes_Click(System::Object^ sender, System::EventArgs^ e) {

		bool ErrorFlag = false;

		String^ SystemNumber = "";
		SystemNumber = textBox1->Text;

		string StringNumber = "";
		StringNumber = ToStdstring(SystemNumber);

		int ID = 0;

		try {
			ID = stoi(StringNumber);

		}
		catch (...) {

			MessageBox::Show("Ошибка. Проверьте корректность вводимых данных.", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			ErrorFlag = true;

		}

		if (ErrorFlag == false) {

			if (DeleteLineFromDB(ID)) MessageBox::Show("Строка удалена.", L"Успешно", MessageBoxButtons::OK, MessageBoxIcon::Information);
			else MessageBox::Show("Ошибка. Строка отсутствует.", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}

		this->Close();
	}
	private: System::Void button_cancel_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Close();

	}
	private: System::Void FormDeleteLine_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
