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

		static bool spaceSceneChannel;

		static bool waterSceneChannel;
		static float frequencyVal;
		static float amplitudeVal;
		static bool wireframeChannel;
		static bool tintChannel;


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
	private: System::Windows::Forms::RadioButton^ spaceSceneButton;
	private: System::Windows::Forms::RadioButton^ WaterButton;




	private: System::Windows::Forms::Label^ frequencyLabel;
	private: System::Windows::Forms::Label^ amplitudeLabel;
	private: System::Windows::Forms::Label^ frequencyValLabel;
	private: System::Windows::Forms::Label^ amplitudeValLabel;
	private: System::Windows::Forms::TrackBar^ trackBarFrequency;
	private: System::Windows::Forms::TrackBar^ trackBarAmplitude;
	private: System::Windows::Forms::CheckBox^ checkBoxWireframe;
	private: System::Windows::Forms::CheckBox^ checkBoxTintBlue;






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
			spaceSceneChannel = spaceSceneButton->Checked;
			waterSceneChannel = WaterButton->Checked;
			frequencyVal = 400.0f;
			amplitudeVal = 1.0f;
			wireframeChannel = checkBoxWireframe->Checked;
			tintChannel = checkBoxTintBlue->Checked;
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
			this->spaceSceneButton = (gcnew System::Windows::Forms::RadioButton());
			this->WaterButton = (gcnew System::Windows::Forms::RadioButton());
			this->frequencyLabel = (gcnew System::Windows::Forms::Label());
			this->amplitudeLabel = (gcnew System::Windows::Forms::Label());
			this->frequencyValLabel = (gcnew System::Windows::Forms::Label());
			this->amplitudeValLabel = (gcnew System::Windows::Forms::Label());
			this->trackBarFrequency = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarAmplitude = (gcnew System::Windows::Forms::TrackBar());
			this->checkBoxWireframe = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxTintBlue = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSpecular))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rComponent))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gComponent))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bComponent))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarFrequency))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarAmplitude))->BeginInit();
			this->SuspendLayout();
			// 
			// moveLightButton
			// 
			this->moveLightButton->AutoSize = true;
			this->moveLightButton->Checked = true;
			this->moveLightButton->Location = System::Drawing::Point(16, 12);
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
			this->resetLightButton->Location = System::Drawing::Point(15, 35);
			this->resetLightButton->Name = L"resetLightButton";
			this->resetLightButton->Size = System::Drawing::Size(119, 23);
			this->resetLightButton->TabIndex = 1;
			this->resetLightButton->Text = L"Reset Light Position";
			this->resetLightButton->UseVisualStyleBackColor = true;
			this->resetLightButton->Click += gcnew System::EventHandler(this, &ToolWindow::resetLightButton_Click);
			// 
			// trackBarSpecular
			// 
			this->trackBarSpecular->Location = System::Drawing::Point(106, 83);
			this->trackBarSpecular->Maximum = 128;
			this->trackBarSpecular->Name = L"trackBarSpecular";
			this->trackBarSpecular->Size = System::Drawing::Size(311, 45);
			this->trackBarSpecular->TabIndex = 2;
			this->trackBarSpecular->Value = 4;
			this->trackBarSpecular->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBarSpecular_Scroll);
			// 
			// rComponent
			// 
			this->rComponent->Location = System::Drawing::Point(106, 136);
			this->rComponent->Maximum = 300;
			this->rComponent->Name = L"rComponent";
			this->rComponent->Size = System::Drawing::Size(311, 45);
			this->rComponent->TabIndex = 3;
			this->rComponent->Value = 100;
			this->rComponent->Scroll += gcnew System::EventHandler(this, &ToolWindow::rComponent_Scroll);
			// 
			// gComponent
			// 
			this->gComponent->Location = System::Drawing::Point(106, 187);
			this->gComponent->Maximum = 300;
			this->gComponent->Name = L"gComponent";
			this->gComponent->Size = System::Drawing::Size(311, 45);
			this->gComponent->TabIndex = 4;
			this->gComponent->Value = 100;
			this->gComponent->Scroll += gcnew System::EventHandler(this, &ToolWindow::gComponent_Scroll);
			// 
			// bComponent
			// 
			this->bComponent->Location = System::Drawing::Point(106, 240);
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
			this->specularLabel->Location = System::Drawing::Point(12, 83);
			this->specularLabel->Name = L"specularLabel";
			this->specularLabel->Size = System::Drawing::Size(92, 13);
			this->specularLabel->TabIndex = 6;
			this->specularLabel->Text = L"Specular Strength";
			this->specularLabel->Click += gcnew System::EventHandler(this, &ToolWindow::trackBarSpecular_Scroll);
			// 
			// labelR
			// 
			this->labelR->AutoSize = true;
			this->labelR->Location = System::Drawing::Point(12, 134);
			this->labelR->Name = L"labelR";
			this->labelR->Size = System::Drawing::Size(87, 13);
			this->labelR->TabIndex = 7;
			this->labelR->Text = L"Specular Color R";
			// 
			// labelG
			// 
			this->labelG->AutoSize = true;
			this->labelG->Location = System::Drawing::Point(84, 179);
			this->labelG->Name = L"labelG";
			this->labelG->Size = System::Drawing::Size(15, 13);
			this->labelG->TabIndex = 9;
			this->labelG->Text = L"G";
			// 
			// labelB
			// 
			this->labelB->AutoSize = true;
			this->labelB->Location = System::Drawing::Point(80, 240);
			this->labelB->Name = L"labelB";
			this->labelB->Size = System::Drawing::Size(14, 13);
			this->labelB->TabIndex = 10;
			this->labelB->Text = L"B";
			// 
			// specularValueLabel
			// 
			this->specularValueLabel->AutoSize = true;
			this->specularValueLabel->Location = System::Drawing::Point(441, 83);
			this->specularValueLabel->Name = L"specularValueLabel";
			this->specularValueLabel->Size = System::Drawing::Size(13, 13);
			this->specularValueLabel->TabIndex = 11;
			this->specularValueLabel->Text = L"4";
			// 
			// rValueLabel
			// 
			this->rValueLabel->AutoSize = true;
			this->rValueLabel->Location = System::Drawing::Point(441, 136);
			this->rValueLabel->Name = L"rValueLabel";
			this->rValueLabel->Size = System::Drawing::Size(28, 13);
			this->rValueLabel->TabIndex = 12;
			this->rValueLabel->Text = L"1.00";
			// 
			// gValueLabel
			// 
			this->gValueLabel->AutoSize = true;
			this->gValueLabel->Location = System::Drawing::Point(441, 187);
			this->gValueLabel->Name = L"gValueLabel";
			this->gValueLabel->Size = System::Drawing::Size(28, 13);
			this->gValueLabel->TabIndex = 13;
			this->gValueLabel->Text = L"1.00";
			// 
			// bValueLabel
			// 
			this->bValueLabel->AutoSize = true;
			this->bValueLabel->Location = System::Drawing::Point(441, 254);
			this->bValueLabel->Name = L"bValueLabel";
			this->bValueLabel->Size = System::Drawing::Size(28, 13);
			this->bValueLabel->TabIndex = 14;
			this->bValueLabel->Text = L"1.00";
			// 
			// transformRadioButton
			// 
			this->transformRadioButton->AutoSize = true;
			this->transformRadioButton->Location = System::Drawing::Point(15, 285);
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
			this->resetTransformButton->Location = System::Drawing::Point(12, 318);
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
			this->translateCheckBox->Location = System::Drawing::Point(17, 357);
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
			this->rotateCheckBox->Location = System::Drawing::Point(16, 380);
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
			this->scaleCheckBox->Location = System::Drawing::Point(17, 403);
			this->scaleCheckBox->Name = L"scaleCheckBox";
			this->scaleCheckBox->Size = System::Drawing::Size(53, 17);
			this->scaleCheckBox->TabIndex = 19;
			this->scaleCheckBox->Text = L"Scale";
			this->scaleCheckBox->UseVisualStyleBackColor = true;
			this->scaleCheckBox->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::scaleCheckBox_CheckedChanged);
			// 
			// spaceSceneButton
			// 
			this->spaceSceneButton->AutoSize = true;
			this->spaceSceneButton->Location = System::Drawing::Point(12, 616);
			this->spaceSceneButton->Name = L"spaceSceneButton";
			this->spaceSceneButton->Size = System::Drawing::Size(90, 17);
			this->spaceSceneButton->TabIndex = 20;
			this->spaceSceneButton->TabStop = true;
			this->spaceSceneButton->Text = L"Space Scene";
			this->spaceSceneButton->UseVisualStyleBackColor = true;
			this->spaceSceneButton->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::spaceSceneButton_CheckedChanged);
			// 
			// WaterButton
			// 
			this->WaterButton->AutoSize = true;
			this->WaterButton->Location = System::Drawing::Point(16, 426);
			this->WaterButton->Name = L"WaterButton";
			this->WaterButton->Size = System::Drawing::Size(88, 17);
			this->WaterButton->TabIndex = 21;
			this->WaterButton->TabStop = true;
			this->WaterButton->Text = L"Water Scene";
			this->WaterButton->UseVisualStyleBackColor = true;
			this->WaterButton->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::WaterButton_CheckedChanged);
			// 
			// frequencyLabel
			// 
			this->frequencyLabel->AutoSize = true;
			this->frequencyLabel->Location = System::Drawing::Point(39, 456);
			this->frequencyLabel->Name = L"frequencyLabel";
			this->frequencyLabel->Size = System::Drawing::Size(57, 13);
			this->frequencyLabel->TabIndex = 24;
			this->frequencyLabel->Text = L"Frequency";
			// 
			// amplitudeLabel
			// 
			this->amplitudeLabel->AutoSize = true;
			this->amplitudeLabel->Location = System::Drawing::Point(40, 511);
			this->amplitudeLabel->Name = L"amplitudeLabel";
			this->amplitudeLabel->Size = System::Drawing::Size(47, 13);
			this->amplitudeLabel->TabIndex = 25;
			this->amplitudeLabel->Text = L"Amplitde";
			// 
			// frequencyValLabel
			// 
			this->frequencyValLabel->AutoSize = true;
			this->frequencyValLabel->Location = System::Drawing::Point(451, 456);
			this->frequencyValLabel->Name = L"frequencyValLabel";
			this->frequencyValLabel->Size = System::Drawing::Size(28, 13);
			this->frequencyValLabel->TabIndex = 26;
			this->frequencyValLabel->Text = L"4.00";
			// 
			// amplitudeValLabel
			// 
			this->amplitudeValLabel->AutoSize = true;
			this->amplitudeValLabel->Location = System::Drawing::Point(449, 515);
			this->amplitudeValLabel->Name = L"amplitudeValLabel";
			this->amplitudeValLabel->Size = System::Drawing::Size(28, 13);
			this->amplitudeValLabel->TabIndex = 27;
			this->amplitudeValLabel->Text = L"0.01";
			// 
			// trackBarFrequency
			// 
			this->trackBarFrequency->Location = System::Drawing::Point(106, 444);
			this->trackBarFrequency->Maximum = 400;
			this->trackBarFrequency->Name = L"trackBarFrequency";
			this->trackBarFrequency->Size = System::Drawing::Size(311, 45);
			this->trackBarFrequency->TabIndex = 28;
			this->trackBarFrequency->Value = 400;
			this->trackBarFrequency->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBarFrequency_Scroll);
			// 
			// trackBarAmplitude
			// 
			this->trackBarAmplitude->Location = System::Drawing::Point(106, 511);
			this->trackBarAmplitude->Maximum = 100;
			this->trackBarAmplitude->Name = L"trackBarAmplitude";
			this->trackBarAmplitude->Size = System::Drawing::Size(311, 45);
			this->trackBarAmplitude->TabIndex = 29;
			this->trackBarAmplitude->Value = 1;
			this->trackBarAmplitude->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBarAmplitude_Scroll);
			// 
			// checkBoxWireframe
			// 
			this->checkBoxWireframe->AutoSize = true;
			this->checkBoxWireframe->Location = System::Drawing::Point(19, 566);
			this->checkBoxWireframe->Name = L"checkBoxWireframe";
			this->checkBoxWireframe->Size = System::Drawing::Size(112, 17);
			this->checkBoxWireframe->TabIndex = 30;
			this->checkBoxWireframe->Text = L"Wireframe Render";
			this->checkBoxWireframe->UseVisualStyleBackColor = true;
			this->checkBoxWireframe->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::checkBoxWireframe_CheckedChanged);
			// 
			// checkBoxTintBlue
			// 
			this->checkBoxTintBlue->AutoSize = true;
			this->checkBoxTintBlue->Location = System::Drawing::Point(19, 589);
			this->checkBoxTintBlue->Name = L"checkBoxTintBlue";
			this->checkBoxTintBlue->Size = System::Drawing::Size(68, 17);
			this->checkBoxTintBlue->TabIndex = 31;
			this->checkBoxTintBlue->Text = L"Tint Blue";
			this->checkBoxTintBlue->UseVisualStyleBackColor = true;
			this->checkBoxTintBlue->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::checkBoxTintBlue_CheckedChanged);
			// 
			// ToolWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(586, 636);
			this->Controls->Add(this->checkBoxTintBlue);
			this->Controls->Add(this->checkBoxWireframe);
			this->Controls->Add(this->trackBarAmplitude);
			this->Controls->Add(this->trackBarFrequency);
			this->Controls->Add(this->amplitudeValLabel);
			this->Controls->Add(this->frequencyValLabel);
			this->Controls->Add(this->amplitudeLabel);
			this->Controls->Add(this->frequencyLabel);
			this->Controls->Add(this->WaterButton);
			this->Controls->Add(this->spaceSceneButton);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarFrequency))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarAmplitude))->EndInit();
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
	private: System::Void spaceSceneButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		spaceSceneChannel = spaceSceneButton->Checked;
	}


	private: System::Void WaterButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		waterSceneChannel = WaterButton->Checked;
	}



	private: System::Void trackBarFrequency_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		frequencyVal = trackBarFrequency->Value / 100.0f;
		frequencyValLabel->Text = (frequencyVal).ToString();
	}
	private: System::Void trackBarAmplitude_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		amplitudeVal = trackBarAmplitude->Value / 100.0f;
		amplitudeValLabel->Text = (amplitudeVal).ToString();
	}
	private: System::Void checkBoxWireframe_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		wireframeChannel = checkBoxWireframe->Checked;

	}
	private: System::Void checkBoxTintBlue_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		tintChannel = checkBoxTintBlue->Checked;
	}
	};
}
