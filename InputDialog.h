#pragma once

namespace ContactsApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    ref class InputDialog : public Form {
    private:
        Label^ titleLabel;
        TextBox^ inputTextBox;
        Button^ okButton;
        Button^ cancelButton;

    public:
        String^ InputValue;

        InputDialog(String^ title, String^ prompt) {
            this->Text = title;
            this->Size = Drawing::Size(300, 150);
            this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedDialog;
            this->StartPosition = FormStartPosition::CenterScreen;
            this->InputValue = nullptr;

            titleLabel = gcnew Label();
            titleLabel->Text = prompt;
            titleLabel->Location = Drawing::Point(10, 10);
            titleLabel->AutoSize = true;
            this->Controls->Add(titleLabel);

            inputTextBox = gcnew TextBox();
            inputTextBox->Location = Drawing::Point(10, 40);
            inputTextBox->Width = 260;
            this->Controls->Add(inputTextBox);

            okButton = gcnew Button();
            okButton->Text = "OK";
            okButton->Location = Drawing::Point(95, 80);
            okButton->Click += gcnew EventHandler(this, &InputDialog::OKButton_Click);
            this->Controls->Add(okButton);

            cancelButton = gcnew Button();
            cancelButton->Text = "Cancel";
            cancelButton->Location = Drawing::Point(175, 80);
            cancelButton->Click += gcnew EventHandler(this, &InputDialog::CancelButton_Click);
            this->Controls->Add(cancelButton);
        }

    private:
        void OKButton_Click(Object^ sender, EventArgs^ e) {
            this->InputValue = inputTextBox->Text;
            this->Close();
        }

        void CancelButton_Click(Object^ sender, EventArgs^ e) {
            this->InputValue = nullptr;
            this->Close();
        }
    private: System::Void InitializeComponent() {
        this->SuspendLayout();
        // 
        // InputDialog
        // 
        this->ClientSize = System::Drawing::Size(512, 402);
        this->Name = L"InputDialog";
        this->Load += gcnew System::EventHandler(this, &InputDialog::InputDialog_Load);
        this->ResumeLayout(false);

    }
    private: System::Void InputDialog_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}
