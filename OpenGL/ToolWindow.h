#pragma once

namespace OpenGL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ToolWindow
	/// </summary>
	public ref class ToolWindow : public System::Windows::Forms::Form
	{
	public:
		ToolWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ToolWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^ Red_Channel;
	private: System::Windows::Forms::CheckBox^ Green_Channel;
	private: System::Windows::Forms::CheckBox^ Blue_Channel;

	protected:

	protected:

	protected:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Red_Channel = (gcnew System::Windows::Forms::CheckBox());
			this->Green_Channel = (gcnew System::Windows::Forms::CheckBox());
			this->Blue_Channel = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// Red_Channel
			// 
			this->Red_Channel->AutoSize = true;
			this->Red_Channel->Location = System::Drawing::Point(13, 23);
			this->Red_Channel->Name = L"Red_Channel";
			this->Red_Channel->Size = System::Drawing::Size(88, 17);
			this->Red_Channel->TabIndex = 0;
			this->Red_Channel->Text = L"Red Channel";
			this->Red_Channel->UseVisualStyleBackColor = true;
			this->Red_Channel->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::checkBox1_CheckedChanged_1);
			// 
			// Green_Channel
			// 
			this->Green_Channel->AutoSize = true;
			this->Green_Channel->Location = System::Drawing::Point(13, 62);
			this->Green_Channel->Name = L"Green_Channel";
			this->Green_Channel->Size = System::Drawing::Size(97, 17);
			this->Green_Channel->TabIndex = 1;
			this->Green_Channel->Text = L"Green Channel";
			this->Green_Channel->UseVisualStyleBackColor = true;
			this->Green_Channel->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::checkBox1_CheckedChanged_2);
			// 
			// Blue_Channel
			// 
			this->Blue_Channel->AutoSize = true;
			this->Blue_Channel->Location = System::Drawing::Point(13, 101);
			this->Blue_Channel->Name = L"Blue_Channel";
			this->Blue_Channel->Size = System::Drawing::Size(89, 17);
			this->Blue_Channel->TabIndex = 2;
			this->Blue_Channel->Text = L"Blue Channel";
			this->Blue_Channel->UseVisualStyleBackColor = true;
			// 
			// ToolWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->Blue_Channel);
			this->Controls->Add(this->Green_Channel);
			this->Controls->Add(this->Red_Channel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"ToolWindow";
			this->Text = L"ToolWindow";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &ToolWindow::ToolWindow_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ToolWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBox1_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBox1_CheckedChanged_2(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
