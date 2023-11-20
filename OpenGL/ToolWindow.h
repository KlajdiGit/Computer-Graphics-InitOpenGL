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
	static bool resetLightButton;

	private: System::Windows::Forms::RadioButton^ moveLight;
	private: System::Windows::Forms::RadioButton^ colorByPosition;
	private: System::Windows::Forms::RadioButton^ moveCubesToSphere;
	private: System::Windows::Forms::Button^ resetLightPosition;
	private: System::Windows::Forms::Button^ resetTeapotPosition;
	private: System::Windows::Forms::TrackBar^ specularStrength;
	private: System::Windows::Forms::TrackBar^ componentR;
	private: System::Windows::Forms::TrackBar^ componentG;
	private: System::Windows::Forms::TrackBar^ componentB;
	private: System::Windows::Forms::Label^ specularStrengthLabel;
	private: System::Windows::Forms::Label^ specularColorLabel;
	private: System::Windows::Forms::Label^ rLabel;
	private: System::Windows::Forms::Label^ gLabel;
	private: System::Windows::Forms::Label^ bLabel;
	private: System::Windows::Forms::Label^ specStrengthLabelVal;
	private: System::Windows::Forms::Label^ rLabelVal;
	private: System::Windows::Forms::Label^ gLabelVal;
	private: System::Windows::Forms::Label^ bLabelVal;

	public:

	public:


	public:


		ToolWindow(void)
		{
			InitializeComponent();

			trackbarR = 100.0f;
			trackbarG = 100.0f;
			trackbarB = 100.0f;
			trackbarSpecStrength = 4.0f;
			resetLightButton = false;
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
			this->moveLight = (gcnew System::Windows::Forms::RadioButton());
			this->colorByPosition = (gcnew System::Windows::Forms::RadioButton());
			this->moveCubesToSphere = (gcnew System::Windows::Forms::RadioButton());
			this->resetLightPosition = (gcnew System::Windows::Forms::Button());
			this->resetTeapotPosition = (gcnew System::Windows::Forms::Button());
			this->specularStrength = (gcnew System::Windows::Forms::TrackBar());
			this->componentR = (gcnew System::Windows::Forms::TrackBar());
			this->componentG = (gcnew System::Windows::Forms::TrackBar());
			this->componentB = (gcnew System::Windows::Forms::TrackBar());
			this->specularStrengthLabel = (gcnew System::Windows::Forms::Label());
			this->specularColorLabel = (gcnew System::Windows::Forms::Label());
			this->rLabel = (gcnew System::Windows::Forms::Label());
			this->gLabel = (gcnew System::Windows::Forms::Label());
			this->bLabel = (gcnew System::Windows::Forms::Label());
			this->specStrengthLabelVal = (gcnew System::Windows::Forms::Label());
			this->rLabelVal = (gcnew System::Windows::Forms::Label());
			this->gLabelVal = (gcnew System::Windows::Forms::Label());
			this->bLabelVal = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->specularStrength))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->componentR))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->componentG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->componentB))->BeginInit();
			this->SuspendLayout();
			// 
			// moveLight
			// 
			this->moveLight->AutoSize = true;
			this->moveLight->Checked = true;
			this->moveLight->Location = System::Drawing::Point(61, 38);
			this->moveLight->Name = L"moveLight";
			this->moveLight->Size = System::Drawing::Size(78, 17);
			this->moveLight->TabIndex = 0;
			this->moveLight->TabStop = true;
			this->moveLight->Text = L"Move Light";
			this->moveLight->UseVisualStyleBackColor = true;
			// 
			// colorByPosition
			// 
			this->colorByPosition->AutoSize = true;
			this->colorByPosition->Location = System::Drawing::Point(61, 368);
			this->colorByPosition->Name = L"colorByPosition";
			this->colorByPosition->Size = System::Drawing::Size(104, 17);
			this->colorByPosition->TabIndex = 1;
			this->colorByPosition->Text = L"Color By Position";
			this->colorByPosition->UseVisualStyleBackColor = true;
			// 
			// moveCubesToSphere
			// 
			this->moveCubesToSphere->AutoSize = true;
			this->moveCubesToSphere->Location = System::Drawing::Point(61, 490);
			this->moveCubesToSphere->Name = L"moveCubesToSphere";
			this->moveCubesToSphere->Size = System::Drawing::Size(134, 17);
			this->moveCubesToSphere->TabIndex = 2;
			this->moveCubesToSphere->Text = L"Move Cubes to Sphere";
			this->moveCubesToSphere->UseVisualStyleBackColor = true;
			// 
			// resetLightPosition
			// 
			this->resetLightPosition->Location = System::Drawing::Point(61, 70);
			this->resetLightPosition->Name = L"resetLightPosition";
			this->resetLightPosition->Size = System::Drawing::Size(116, 23);
			this->resetLightPosition->TabIndex = 3;
			this->resetLightPosition->Text = L"Reset Light Position";
			this->resetLightPosition->UseVisualStyleBackColor = true;
			this->resetLightPosition->Click += gcnew System::EventHandler(this, &ToolWindow::resetLightPosition_Click);
			// 
			// resetTeapotPosition
			// 
			this->resetTeapotPosition->Location = System::Drawing::Point(61, 413);
			this->resetTeapotPosition->Name = L"resetTeapotPosition";
			this->resetTeapotPosition->Size = System::Drawing::Size(131, 23);
			this->resetTeapotPosition->TabIndex = 4;
			this->resetTeapotPosition->Text = L"Reset Teapot Position";
			this->resetTeapotPosition->UseVisualStyleBackColor = true;
			// 
			// specularStrength
			// 
			this->specularStrength->Location = System::Drawing::Point(134, 114);
			this->specularStrength->Maximum = 128;
			this->specularStrength->Minimum = 1;
			this->specularStrength->Name = L"specularStrength";
			this->specularStrength->Size = System::Drawing::Size(469, 45);
			this->specularStrength->TabIndex = 5;
			this->specularStrength->Value = 4;
			this->specularStrength->Scroll += gcnew System::EventHandler(this, &ToolWindow::specularStrength_Scroll);
			// 
			// componentR
			// 
			this->componentR->Location = System::Drawing::Point(134, 178);
			this->componentR->Maximum = 300;
			this->componentR->Name = L"componentR";
			this->componentR->Size = System::Drawing::Size(469, 45);
			this->componentR->TabIndex = 6;
			this->componentR->Value = 100;
			this->componentR->Scroll += gcnew System::EventHandler(this, &ToolWindow::componentR_Scroll);
			// 
			// componentG
			// 
			this->componentG->Location = System::Drawing::Point(134, 248);
			this->componentG->Maximum = 300;
			this->componentG->Name = L"componentG";
			this->componentG->Size = System::Drawing::Size(469, 45);
			this->componentG->TabIndex = 7;
			this->componentG->Value = 100;
			this->componentG->Scroll += gcnew System::EventHandler(this, &ToolWindow::componentG_Scroll);
			// 
			// componentB
			// 
			this->componentB->Location = System::Drawing::Point(134, 317);
			this->componentB->Maximum = 300;
			this->componentB->Name = L"componentB";
			this->componentB->Size = System::Drawing::Size(458, 45);
			this->componentB->TabIndex = 8;
			this->componentB->Value = 100;
			this->componentB->Scroll += gcnew System::EventHandler(this, &ToolWindow::componentB_Scroll);
			// 
			// specularStrengthLabel
			// 
			this->specularStrengthLabel->AutoSize = true;
			this->specularStrengthLabel->Location = System::Drawing::Point(12, 114);
			this->specularStrengthLabel->Name = L"specularStrengthLabel";
			this->specularStrengthLabel->Size = System::Drawing::Size(89, 13);
			this->specularStrengthLabel->TabIndex = 9;
			this->specularStrengthLabel->Text = L"Specular Strengh";
			// 
			// specularColorLabel
			// 
			this->specularColorLabel->AutoSize = true;
			this->specularColorLabel->Location = System::Drawing::Point(12, 178);
			this->specularColorLabel->Name = L"specularColorLabel";
			this->specularColorLabel->Size = System::Drawing::Size(76, 13);
			this->specularColorLabel->TabIndex = 10;
			this->specularColorLabel->Text = L"Specular Color";
			// 
			// rLabel
			// 
			this->rLabel->AutoSize = true;
			this->rLabel->Location = System::Drawing::Point(113, 178);
			this->rLabel->Name = L"rLabel";
			this->rLabel->Size = System::Drawing::Size(15, 13);
			this->rLabel->TabIndex = 11;
			this->rLabel->Text = L"R";
			// 
			// gLabel
			// 
			this->gLabel->AutoSize = true;
			this->gLabel->Location = System::Drawing::Point(113, 248);
			this->gLabel->Name = L"gLabel";
			this->gLabel->Size = System::Drawing::Size(15, 13);
			this->gLabel->TabIndex = 12;
			this->gLabel->Text = L"G";
			// 
			// bLabel
			// 
			this->bLabel->AutoSize = true;
			this->bLabel->Location = System::Drawing::Point(113, 317);
			this->bLabel->Name = L"bLabel";
			this->bLabel->Size = System::Drawing::Size(14, 13);
			this->bLabel->TabIndex = 13;
			this->bLabel->Text = L"B";
			// 
			// specStrengthLabelVal
			// 
			this->specStrengthLabelVal->AutoSize = true;
			this->specStrengthLabelVal->Location = System::Drawing::Point(655, 114);
			this->specStrengthLabelVal->Name = L"specStrengthLabelVal";
			this->specStrengthLabelVal->Size = System::Drawing::Size(13, 13);
			this->specStrengthLabelVal->TabIndex = 14;
			this->specStrengthLabelVal->Text = L"4";
			// 
			// rLabelVal
			// 
			this->rLabelVal->AutoSize = true;
			this->rLabelVal->Location = System::Drawing::Point(646, 178);
			this->rLabelVal->Name = L"rLabelVal";
			this->rLabelVal->Size = System::Drawing::Size(22, 13);
			this->rLabelVal->TabIndex = 15;
			this->rLabelVal->Text = L"1.0";
			// 
			// gLabelVal
			// 
			this->gLabelVal->AutoSize = true;
			this->gLabelVal->Location = System::Drawing::Point(646, 248);
			this->gLabelVal->Name = L"gLabelVal";
			this->gLabelVal->Size = System::Drawing::Size(22, 13);
			this->gLabelVal->TabIndex = 16;
			this->gLabelVal->Text = L"1.0";
			// 
			// bLabelVal
			// 
			this->bLabelVal->AutoSize = true;
			this->bLabelVal->Location = System::Drawing::Point(646, 317);
			this->bLabelVal->Name = L"bLabelVal";
			this->bLabelVal->Size = System::Drawing::Size(22, 13);
			this->bLabelVal->TabIndex = 17;
			this->bLabelVal->Text = L"1.0";
			// 
			// ToolWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(733, 543);
			this->Controls->Add(this->bLabelVal);
			this->Controls->Add(this->gLabelVal);
			this->Controls->Add(this->rLabelVal);
			this->Controls->Add(this->specStrengthLabelVal);
			this->Controls->Add(this->bLabel);
			this->Controls->Add(this->gLabel);
			this->Controls->Add(this->rLabel);
			this->Controls->Add(this->specularColorLabel);
			this->Controls->Add(this->specularStrengthLabel);
			this->Controls->Add(this->componentB);
			this->Controls->Add(this->componentG);
			this->Controls->Add(this->componentR);
			this->Controls->Add(this->specularStrength);
			this->Controls->Add(this->resetTeapotPosition);
			this->Controls->Add(this->resetLightPosition);
			this->Controls->Add(this->moveCubesToSphere);
			this->Controls->Add(this->colorByPosition);
			this->Controls->Add(this->moveLight);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"ToolWindow";
			this->Text = L"ToolWindow";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &ToolWindow::ToolWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->specularStrength))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->componentR))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->componentG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->componentB))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ToolWindow_Load(System::Object^ sender, System::EventArgs^ e) {
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

    private: System::Void componentR_Scroll(System::Object^ sender, System::EventArgs^ e) {
		if (moveLight->Checked)
		{
			trackbarR = componentR->Value / 100.0f;
			rLabelVal->Text = (trackbarR).ToString();
		}
		else
		{
			componentR->Value = 100.0f;
			trackbarR = componentR->Value / 100.0f;
			rLabelVal->Text = (trackbarR).ToString();
		}
    }
    
    private: System::Void componentG_Scroll(System::Object^ sender, System::EventArgs^ e) {
		if (moveLight->Checked)
		{
			trackbarG = componentG->Value / 100.0f;
			gLabelVal->Text = (trackbarG).ToString();
		}
		else
		{
			componentG->Value = 100.0f;
			trackbarG = componentG->Value / 100.0f;
			gLabelVal->Text = (trackbarG).ToString();
		}
    }
    
    private: System::Void componentB_Scroll(System::Object^ sender, System::EventArgs^ e) {
		if (moveLight->Checked)
		{
			trackbarB = componentB->Value / 100.0f;
			bLabelVal->Text = (trackbarB).ToString();
		}
		else
		{
			componentB->Value = 100.0f;
			trackbarB = componentB->Value / 100.0f;
			bLabelVal->Text = (trackbarB).ToString();
		}
	}
    
    private: System::Void specularStrength_Scroll(System::Object^ sender, System::EventArgs^ e) {
		if (moveLight->Checked)
		{
			trackbarSpecStrength = specularStrength->Value;
			specStrengthLabelVal->Text = (trackbarSpecStrength).ToString();
		}
		else
		{
			trackbarSpecStrength = 4;
			specStrengthLabelVal->Text = (trackbarSpecStrength).ToString();
		}
		
    }
private: System::Void resetLightPosition_Click(System::Object^ sender, System::EventArgs^ e) {
	resetLightButton = true;
}
};
}
