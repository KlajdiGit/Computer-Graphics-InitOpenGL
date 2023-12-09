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
		static float trackbarR;
		static float trackbarG;
		static float trackbarB;
		static float trackbarSpecStrength;
		static bool resetLightChannel;
		static bool moveLightChannel;
		static bool transformChannel;

		static bool resetTansformChannel;
		static bool translateChannel;
		static bool rotateChannel;
		static bool scaleChannel;


	private: System::Windows::Forms::RadioButton^ moveLightButton;
	public:
	private: System::Windows::Forms::Button^ resetLightButton;
	private: System::Windows::Forms::TrackBar^ trackBarSpecular;
	private: System::Windows::Forms::TrackBar^ rComponent;
	private: System::Windows::Forms::TrackBar^ gComponent;
	private: System::Windows::Forms::TrackBar^ bComponent;




	private: System::Windows::Forms::Label^ specularLabel;
	private: System::Windows::Forms::Label^ labelR;
	private: System::Windows::Forms::Label^ labelG;
	private: System::Windows::Forms::Label^ labelB;
	private: System::Windows::Forms::Label^ specularValueLabel;
	private: System::Windows::Forms::Label^ rValueLabel;
	private: System::Windows::Forms::Label^ gValueLabel;
	private: System::Windows::Forms::RadioButton^ transformRadioButton;
	private: System::Windows::Forms::Button^ resetTransformButton;
	private: System::Windows::Forms::CheckBox^ translateCheckBox;
	private: System::Windows::Forms::CheckBox^ rotateCheckBox;
	private: System::Windows::Forms::CheckBox^ scaleCheckBox;

	private: System::Windows::Forms::Label^ bValueLabel;







	public:
		   ToolWindow(void)
		   {
			   InitializeComponent();
			   trackbarR = 100.0f;
			   trackbarG = 100.0f;
			   trackbarB = 100.0f;
			   trackbarSpecStrength = 4.0f;
			   resetLightChannel = false;
			   moveLightChannel = moveLightButton->Checked;
			   transformChannel = transformRadioButton->Checked;

			   resetTansformChannel = false;
			   translateChannel = translateCheckBox->Checked;
			   rotateChannel = rotateCheckBox->Checked;
			   scaleChannel = scaleCheckBox->Checked;
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
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->moveLightButton = (gcnew System::Windows::Forms::RadioButton());
			this->resetLightButton = (gcnew System::Windows::Forms::Button());
			this->trackBarSpecular = (gcnew System::Windows::Forms::TrackBar());
			this->rComponent = (gcnew System::Windows::Forms::TrackBar());
			this->gComponent = (gcnew System::Windows::Forms::TrackBar());
			this->bComponent = (gcnew System::Windows::Forms::TrackBar());
			this->specularLabel = (gcnew System::Windows::Forms::Label());
			this->labelR = (gcnew System::Windows::Forms::Label());
			this->labelG = (gcnew System::Windows::Forms::Label());
			this->labelB = (gcnew System::Windows::Forms::Label());
			this->specularValueLabel = (gcnew System::Windows::Forms::Label());
			this->rValueLabel = (gcnew System::Windows::Forms::Label());
			this->gValueLabel = (gcnew System::Windows::Forms::Label());
			this->bValueLabel = (gcnew System::Windows::Forms::Label());
			this->transformRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->resetTransformButton = (gcnew System::Windows::Forms::Button());
			this->translateCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->rotateCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->scaleCheckBox = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSpecular))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rComponent))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gComponent))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bComponent))->BeginInit();
			this->SuspendLayout();
			// 
			// moveLightButton
			// 
			this->moveLightButton->AutoSize = true;
			this->moveLightButton->Checked = true;
			this->moveLightButton->Location = System::Drawing::Point(22, 23);
			this->moveLightButton->Name = L"moveLightButton";
			this->moveLightButton->Size = System::Drawing::Size(78, 17);
			this->moveLightButton->TabIndex = 0;
			this->moveLightButton->TabStop = true;
			this->moveLightButton->Text = L"Move Light";
			this->moveLightButton->UseVisualStyleBackColor = true;
			this->moveLightButton->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::moveLightButton_CheckedChanged);
			// 
			// resetLightButton
			// 
			this->resetLightButton->Location = System::Drawing::Point(22, 60);
			this->resetLightButton->Name = L"resetLightButton";
			this->resetLightButton->Size = System::Drawing::Size(119, 23);
			this->resetLightButton->TabIndex = 1;
			this->resetLightButton->Text = L"Reset Light Position";
			this->resetLightButton->UseVisualStyleBackColor = true;
			this->resetLightButton->Click += gcnew System::EventHandler(this, &ToolWindow::resetLightButton_Click);
			// 
			// trackBarSpecular
			// 
			this->trackBarSpecular->Location = System::Drawing::Point(106, 101);
			this->trackBarSpecular->Maximum = 128;
			this->trackBarSpecular->Name = L"trackBarSpecular";
			this->trackBarSpecular->Size = System::Drawing::Size(311, 45);
			this->trackBarSpecular->TabIndex = 2;
			this->trackBarSpecular->Value = 4;
			this->trackBarSpecular->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBarSpecular_Scroll);
			// 
			// rComponent
			// 
			this->rComponent->Location = System::Drawing::Point(106, 168);
			this->rComponent->Maximum = 300;
			this->rComponent->Name = L"rComponent";
			this->rComponent->Size = System::Drawing::Size(311, 45);
			this->rComponent->TabIndex = 3;
			this->rComponent->Value = 100;
			this->rComponent->Scroll += gcnew System::EventHandler(this, &ToolWindow::rComponent_Scroll);
			// 
			// gComponent
			// 
			this->gComponent->Location = System::Drawing::Point(106, 232);
			this->gComponent->Maximum = 300;
			this->gComponent->Name = L"gComponent";
			this->gComponent->Size = System::Drawing::Size(311, 45);
			this->gComponent->TabIndex = 4;
			this->gComponent->Value = 100;
			this->gComponent->Scroll += gcnew System::EventHandler(this, &ToolWindow::gComponent_Scroll);
			// 
			// bComponent
			// 
			this->bComponent->Location = System::Drawing::Point(106, 320);
			this->bComponent->Maximum = 300;
			this->bComponent->Name = L"bComponent";
			this->bComponent->Size = System::Drawing::Size(311, 45);
			this->bComponent->TabIndex = 5;
			this->bComponent->Value = 100;
			this->bComponent->Scroll += gcnew System::EventHandler(this, &ToolWindow::bComponent_Scroll);
			// 
			// specularLabel
			// 
			this->specularLabel->AutoSize = true;
			this->specularLabel->Location = System::Drawing::Point(8, 101);
			this->specularLabel->Name = L"specularLabel";
			this->specularLabel->Size = System::Drawing::Size(92, 13);
			this->specularLabel->TabIndex = 6;
			this->specularLabel->Text = L"Specular Strength";
			this->specularLabel->Click += gcnew System::EventHandler(this, &ToolWindow::trackBarSpecular_Scroll);
			// 
			// labelR
			// 
			this->labelR->AutoSize = true;
			this->labelR->Location = System::Drawing::Point(12, 168);
			this->labelR->Name = L"labelR";
			this->labelR->Size = System::Drawing::Size(87, 13);
			this->labelR->TabIndex = 7;
			this->labelR->Text = L"Specular Color R";
			// 
			// labelG
			// 
			this->labelG->AutoSize = true;
			this->labelG->Location = System::Drawing::Point(84, 232);
			this->labelG->Name = L"labelG";
			this->labelG->Size = System::Drawing::Size(15, 13);
			this->labelG->TabIndex = 9;
			this->labelG->Text = L"G";
			// 
			// labelB
			// 
			this->labelB->AutoSize = true;
			this->labelB->Location = System::Drawing::Point(84, 320);
			this->labelB->Name = L"labelB";
			this->labelB->Size = System::Drawing::Size(14, 13);
			this->labelB->TabIndex = 10;
			this->labelB->Text = L"B";
			// 
			// specularValueLabel
			// 
			this->specularValueLabel->AutoSize = true;
			this->specularValueLabel->Location = System::Drawing::Point(441, 101);
			this->specularValueLabel->Name = L"specularValueLabel";
			this->specularValueLabel->Size = System::Drawing::Size(13, 13);
			this->specularValueLabel->TabIndex = 11;
			this->specularValueLabel->Text = L"4";
			// 
			// rValueLabel
			// 
			this->rValueLabel->AutoSize = true;
			this->rValueLabel->Location = System::Drawing::Point(441, 168);
			this->rValueLabel->Name = L"rValueLabel";
			this->rValueLabel->Size = System::Drawing::Size(28, 13);
			this->rValueLabel->TabIndex = 12;
			this->rValueLabel->Text = L"1.00";
			// 
			// gValueLabel
			// 
			this->gValueLabel->AutoSize = true;
			this->gValueLabel->Location = System::Drawing::Point(441, 232);
			this->gValueLabel->Name = L"gValueLabel";
			this->gValueLabel->Size = System::Drawing::Size(28, 13);
			this->gValueLabel->TabIndex = 13;
			this->gValueLabel->Text = L"1.00";
			// 
			// bValueLabel
			// 
			this->bValueLabel->AutoSize = true;
			this->bValueLabel->Location = System::Drawing::Point(441, 320);
			this->bValueLabel->Name = L"bValueLabel";
			this->bValueLabel->Size = System::Drawing::Size(28, 13);
			this->bValueLabel->TabIndex = 14;
			this->bValueLabel->Text = L"1.00";
			// 
			// transformRadioButton
			// 
			this->transformRadioButton->AutoSize = true;
			this->transformRadioButton->Location = System::Drawing::Point(22, 371);
			this->transformRadioButton->Name = L"transformRadioButton";
			this->transformRadioButton->Size = System::Drawing::Size(72, 17);
			this->transformRadioButton->TabIndex = 15;
			this->transformRadioButton->TabStop = true;
			this->transformRadioButton->Text = L"Transform";
			this->transformRadioButton->UseVisualStyleBackColor = true;
			this->transformRadioButton->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::transformRadioButton_CheckedChanged);
			// 
			// resetTransformButton
			// 
			this->resetTransformButton->Location = System::Drawing::Point(22, 411);
			this->resetTransformButton->Name = L"resetTransformButton";
			this->resetTransformButton->Size = System::Drawing::Size(102, 23);
			this->resetTransformButton->TabIndex = 16;
			this->resetTransformButton->Text = L"Reset Transform";
			this->resetTransformButton->UseVisualStyleBackColor = true;
			this->resetTransformButton->Click += gcnew System::EventHandler(this, &ToolWindow::resetTransformButton_Click);
			// 
			// translateCheckBox
			// 
			this->translateCheckBox->AutoSize = true;
			this->translateCheckBox->Location = System::Drawing::Point(22, 452);
			this->translateCheckBox->Name = L"translateCheckBox";
			this->translateCheckBox->Size = System::Drawing::Size(70, 17);
			this->translateCheckBox->TabIndex = 17;
			this->translateCheckBox->Text = L"Translate";
			this->translateCheckBox->UseVisualStyleBackColor = true;
			this->translateCheckBox->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::translateCheckBox_CheckedChanged);
			// 
			// rotateCheckBox
			// 
			this->rotateCheckBox->AutoSize = true;
			this->rotateCheckBox->Location = System::Drawing::Point(22, 475);
			this->rotateCheckBox->Name = L"rotateCheckBox";
			this->rotateCheckBox->Size = System::Drawing::Size(58, 17);
			this->rotateCheckBox->TabIndex = 18;
			this->rotateCheckBox->Text = L"Rotate";
			this->rotateCheckBox->UseVisualStyleBackColor = true;
			this->rotateCheckBox->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::rotateCheckBox_CheckedChanged);
			// 
			// scaleCheckBox
			// 
			this->scaleCheckBox->AutoSize = true;
			this->scaleCheckBox->Location = System::Drawing::Point(22, 498);
			this->scaleCheckBox->Name = L"scaleCheckBox";
			this->scaleCheckBox->Size = System::Drawing::Size(53, 17);
			this->scaleCheckBox->TabIndex = 19;
			this->scaleCheckBox->Text = L"Scale";
			this->scaleCheckBox->UseVisualStyleBackColor = true;
			this->scaleCheckBox->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::scaleCheckBox_CheckedChanged);
			// 
			// ToolWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(586, 558);
			this->Controls->Add(this->scaleCheckBox);
			this->Controls->Add(this->rotateCheckBox);
			this->Controls->Add(this->translateCheckBox);
			this->Controls->Add(this->resetTransformButton);
			this->Controls->Add(this->transformRadioButton);
			this->Controls->Add(this->bValueLabel);
			this->Controls->Add(this->gValueLabel);
			this->Controls->Add(this->rValueLabel);
			this->Controls->Add(this->specularValueLabel);
			this->Controls->Add(this->labelB);
			this->Controls->Add(this->labelG);
			this->Controls->Add(this->labelR);
			this->Controls->Add(this->specularLabel);
			this->Controls->Add(this->bComponent);
			this->Controls->Add(this->gComponent);
			this->Controls->Add(this->rComponent);
			this->Controls->Add(this->trackBarSpecular);
			this->Controls->Add(this->resetLightButton);
			this->Controls->Add(this->moveLightButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"ToolWindow";
			this->Text = L"ToolWindow";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &ToolWindow::ToolWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSpecular))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rComponent))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gComponent))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bComponent))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ToolWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	}



    private: System::Void rComponent_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		trackbarR = rComponent->Value / 100.0f;
		rValueLabel->Text = (trackbarR).ToString();
    }

    private: System::Void trackBarSpecular_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		trackbarSpecStrength = trackBarSpecular->Value;
		specularValueLabel->Text = (trackbarSpecStrength).ToString();
    }
 
    private: System::Void gComponent_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		trackbarG = gComponent->Value / 100.0f;
		gValueLabel->Text = (trackbarG).ToString();
    }

    private: System::Void bComponent_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		trackbarB = bComponent->Value / 100.0f;
		bValueLabel->Text = (trackbarB).ToString();
	}
    private: System::Void resetLightButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		resetLightChannel = true;
    }
    private: System::Void moveLightButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
    {
		moveLightChannel = moveLightButton->Checked;
    }
    private: System::Void transformRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		transformChannel = transformRadioButton->Checked;
    }
    private: System::Void resetTransformButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		resetTansformChannel = true;
    }
    private: System::Void translateCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		translateChannel = translateCheckBox->Checked;
    }
    private: System::Void rotateCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		rotateChannel = rotateCheckBox->Checked;
    }
    private: System::Void scaleCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		scaleChannel = scaleCheckBox->Checked;
    }
};
}
