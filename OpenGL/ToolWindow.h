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

		//static bool RenderRedChannel;
		//static bool RenderGreenChannel;
		 // static bool RenderBlueChannel;
	public: System::Windows::Forms::TrackBar^ trackBarY;
	public: System::Windows::Forms::TrackBar^ trackBarU;
	public: System::Windows::Forms::TrackBar^ trackBarV;
	public: System::Windows::Forms::CheckBox^ invertColors;
	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::Label^ label3;
	public: System::Windows::Forms::Label^ label4;
	public: System::Windows::Forms::Label^ label5;
	public: System::Windows::Forms::Label^ label6;
		 static float trackBarYvalue;
		  static float trackBarUvalue;
		  static float trackBarVvalue;



		ToolWindow(void)
		{
			InitializeComponent();
			/*RenderRedChannel = checkBoxRedChannel->Checked;
			RenderGreenChannel = checkBoxGreenChannel->Checked;
			RenderBlueChannel = checkBoxBlueChannel->Checked;*/
			trackBarYvalue = trackBarY->Value;
			trackBarUvalue = trackBarU->Value;
			trackBarVvalue = trackBarV->Value;

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



	protected:




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
			this->trackBarY = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarU = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarV = (gcnew System::Windows::Forms::TrackBar());
			this->invertColors = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarU))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarV))->BeginInit();
			this->SuspendLayout();
			// 
			// trackBarY
			// 
			this->trackBarY->Location = System::Drawing::Point(60, 32);
			this->trackBarY->Maximum = 200;
			this->trackBarY->Name = L"trackBarY";
			this->trackBarY->Size = System::Drawing::Size(510, 45);
			this->trackBarY->TabIndex = 0;
			this->trackBarY->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBarY_Scroll);
			// 
			// trackBarU
			// 
			this->trackBarU->Location = System::Drawing::Point(60, 124);
			this->trackBarU->Maximum = 200;
			this->trackBarU->Name = L"trackBarU";
			this->trackBarU->Size = System::Drawing::Size(510, 45);
			this->trackBarU->TabIndex = 1;
			this->trackBarU->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBarU_Scroll);
			// 
			// trackBarV
			// 
			this->trackBarV->Location = System::Drawing::Point(60, 216);
			this->trackBarV->Maximum = 200;
			this->trackBarV->Name = L"trackBarV";
			this->trackBarV->Size = System::Drawing::Size(510, 45);
			this->trackBarV->TabIndex = 2;
			this->trackBarV->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBarV_Scroll);
			// 
			// invertColors
			// 
			this->invertColors->AutoSize = true;
			this->invertColors->Location = System::Drawing::Point(22, 292);
			this->invertColors->Name = L"invertColors";
			this->invertColors->Size = System::Drawing::Size(82, 17);
			this->invertColors->TabIndex = 3;
			this->invertColors->Text = L"Inver Colors";
			this->invertColors->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(14, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Y";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(599, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"100%";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(599, 137);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"100%";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(599, 216);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"100%";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(25, 124);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(15, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"U";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(25, 227);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(14, 13);
			this->label6->TabIndex = 9;
			this->label6->Text = L"V";
			// 
			// ToolWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(656, 332);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->invertColors);
			this->Controls->Add(this->trackBarV);
			this->Controls->Add(this->trackBarU);
			this->Controls->Add(this->trackBarY);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"ToolWindow";
			this->Text = L"ToolWindow";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &ToolWindow::ToolWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarU))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarV))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ToolWindow_Load(System::Object^ sender, System::EventArgs^ e) {

		this->trackBarY->Value = 100;
		this->trackBarU->Value = 100;
		this->trackBarV->Value = 100;
		this->trackBarY->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBar_Scroll);
		this->trackBarU->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBar_Scroll);
		this->trackBarV->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBar_Scroll);
	}
	

    private: System::Void trackBar_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		TrackBar^ trackBar = safe_cast<TrackBar^>(sender);
		Label^ label;
		float value = trackBar->Value / 100.0f; // Convert percentage to a value between 0.0 and 1.0

		if (trackBar == this->trackBarY) {
			label = this->label2;
			// Update Y value in shader
		}
		else if (trackBar == this->trackBarU) {
			label = this->label3;
		}
		else if (trackBar == this->trackBarV) {
			label = this->label4;
		}

		label->Text = String::Format("{0}%", trackBar->Value);

    }

private: System::Void trackBarY_Scroll(System::Object^ sender, System::EventArgs^ e) {
	trackBarYvalue = trackBarY->Value;
}

private: System::Void trackBarU_Scroll(System::Object^ sender, System::EventArgs^ e) {
	trackBarUvalue = trackBarU->Value;
}

private: System::Void trackBarV_Scroll(System::Object^ sender, System::EventArgs^ e) {
	trackBarVvalue = trackBarV->Value;
}
};
}



/*private: System::Void checkBoxRedChannel_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	RenderRedChannel = checkBoxRedChannel->Checked;
}
private: System::Void checkBoxGreenChannel_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	RenderGreenChannel = checkBoxGreenChannel->Checked;
}
private: System::Void checkBoxBlueChannel_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	RenderBlueChannel = checkBoxBlueChannel->Checked;
}*/
