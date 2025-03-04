#pragma once
#include "ContactList.h"
namespace ContactsApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class History : public System::Windows::Forms::Form
	{
	public:
		History(void)
		{
			historyPanel = gcnew Panel();
			frequentSearchPanel = gcnew Panel();
			InitializeComponent();
		}
		

		~History()
		{
			if (components)
			{
				delete components;
				
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
		Panel^ historyPanel;
		Panel^ frequentSearchPanel;
	private: System::Windows::Forms::PictureBox^ back;
	private: System::Windows::Forms::Button^ frequent_search;
	private: System::Windows::Forms::PictureBox^ close;


	private: System::Windows::Forms::Label^ heading;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(History::typeid));
			   this->heading = (gcnew System::Windows::Forms::Label());
			   this->back = (gcnew System::Windows::Forms::PictureBox());
			   this->frequent_search = (gcnew System::Windows::Forms::Button());
			   this->close = (gcnew System::Windows::Forms::PictureBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->close))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // heading
			   // 
			   this->heading->AutoSize = true;
			   this->heading->Font = (gcnew System::Drawing::Font(L"Montserrat ExtraBold", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->heading->ForeColor = System::Drawing::Color::White;
			   this->heading->Location = System::Drawing::Point(251, 36);
			   this->heading->Name = L"heading";
			   this->heading->Size = System::Drawing::Size(226, 37);
			   this->heading->TabIndex = 23;
			   this->heading->Text = L"Search History";
			   // 
			   // back
			   // 
			   this->back->ImageLocation = L"left-arrow_white.png";
			   this->back->Location = System::Drawing::Point(53, 37);
			   this->back->Name = L"back";
			   this->back->Size = System::Drawing::Size(36, 36);
			   this->back->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->back->TabIndex = 24;
			   this->back->TabStop = false;
			   this->back->Click += gcnew System::EventHandler(this, &History::back_Click_1);
			   // 
			   // frequent_search
			   // 
			   this->frequent_search->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->frequent_search->BackColor = System::Drawing::Color::MintCream;
			   this->frequent_search->FlatAppearance->BorderColor = System::Drawing::Color::DarkCyan;
			   this->frequent_search->FlatAppearance->BorderSize = 0;
			   this->frequent_search->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->frequent_search->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 8.249999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->frequent_search->ForeColor = System::Drawing::Color::Black;
			   this->frequent_search->Location = System::Drawing::Point(553, 96);
			   this->frequent_search->Name = L"frequent_search";
			   this->frequent_search->Padding = System::Windows::Forms::Padding(8, 0, 8, 0);
			   this->frequent_search->Size = System::Drawing::Size(154, 33);
			   this->frequent_search->TabIndex = 25;
			   this->frequent_search->Text = L"Frequently Searched";
			   this->frequent_search->UseVisualStyleBackColor = false;
			   this->frequent_search->Click += gcnew System::EventHandler(this, &History::frequent_search_Click);
			   // 
			   // close
			   // 
			   this->close->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"close.Image")));
			   this->close->Location = System::Drawing::Point(686, 40);
			   this->close->Name = L"close";
			   this->close->Size = System::Drawing::Size(21, 33);
			   this->close->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->close->TabIndex = 26;
			   this->close->TabStop = false;
			   this->close->Visible = false;
			   this->close->Click += gcnew System::EventHandler(this, &History::close_Click);
			   // 
			   // History
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->AutoScroll = true;
			   this->BackColor = System::Drawing::Color::LightSlateGray;
			   this->ClientSize = System::Drawing::Size(742, 441);
			   this->Controls->Add(this->close);
			   this->Controls->Add(this->frequent_search);
			   this->Controls->Add(this->back);
			   this->Controls->Add(this->heading);
			   this->Name = L"History";
			   this->Text = L"History";
			   this->Load += gcnew System::EventHandler(this, &History::History_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->close))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void History_Load(System::Object^ sender, System::EventArgs^ e) {
		display_history();
	}

		   System::Void display_history()
		   {
			   // Add the history panel which will contain 
			   historyPanel->Controls->Clear();
			   historyPanel->Width = 658;
			   historyPanel->BackColor = Color::Transparent;
			   historyPanel->Location = System::Drawing::Point(17, 60);
			   historyPanel->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
			   this->Controls->Add(historyPanel);
			   List<HistoryObject> history = sh->get_search_history();
			   for (int i = 0; i < history.size(); ++i)
			   {
				   // Create a new Panel control for each contact
				   Panel^ contactPanel = gcnew Panel();
				   contactPanel->BackColor = System::Drawing::Color::White;
				   contactPanel->Location = System::Drawing::Point(17, 90 + i * 120); // Adjust the Y position based on the index
				   contactPanel->Size = System::Drawing::Size(658, 104);

				   // Create and configure PictureBox
				   PictureBox^ pictureBox = gcnew PictureBox();
				   pictureBox->Location = System::Drawing::Point(17, 22);
				   pictureBox->Size = System::Drawing::Size(48, 48);
				   pictureBox->SizeMode = PictureBoxSizeMode::Zoom;
				   pictureBox->ImageLocation = "user.png"; // Adjust the image location
				   contactPanel->Controls->Add(pictureBox); // Add PictureBox to the panel

				   // Create and configure Label for full name
				   Label^ fullNameLabel = gcnew Label();
				   fullNameLabel->AutoSize = true;
				   fullNameLabel->Font = gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					   static_cast<System::Byte>(0));
				   fullNameLabel->ForeColor = System::Drawing::Color::MidnightBlue;
				   fullNameLabel->Location = System::Drawing::Point(99, 22);
				   fullNameLabel->Text = gcnew String((history[i].get_contact().get_first_name() + " " + history[i].get_contact().get_last_name()).c_str());
				   contactPanel->Controls->Add(fullNameLabel); // Add Label to the panel

				   // Create and configure Label for time
				   Label^ TimeLabel = gcnew Label();
				   TimeLabel->AutoSize = true;
				   TimeLabel->Font = gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					   static_cast<System::Byte>(0));
				   TimeLabel->Location = System::Drawing::Point(99, 52);
				   TimeLabel->Text = gcnew String((to_string(history[i].get_time().get_hours()) + ":" + to_string(history[i].get_time().get_minutes()) + ":" + to_string(history[i].get_time().get_seconds())).c_str()); 
				   contactPanel->Controls->Add(TimeLabel); // Add Label to the panel

				   // Create and configure label for date
				   Label^ DateLabel = gcnew Label();
				   DateLabel->AutoSize = true;
				   DateLabel->Font = gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					   static_cast<System::Byte>(0));
				   DateLabel->Location = System::Drawing::Point(99, 70);
				   DateLabel->Text = gcnew String((to_string(history[i].get_date().get_year()) + "/" + to_string(history[i].get_date().get_month()) + "/" + to_string(history[i].get_date().get_day())).c_str()); 
				   contactPanel->Controls->Add(DateLabel); // Add Label to the panel
				   historyPanel->Controls->Add(contactPanel);
			   }
			   historyPanel->AutoSize = true;
			   historyPanel->AutoScroll = true;
		   }

private: System::Void back_Click_1(System::Object^ sender, System::EventArgs^ e) {
	History::Close();
}

private: System::Void frequent_search_Click(System::Object^ sender, System::EventArgs^ e) {
	frequent_search->Hide();
	frequentSearchPanel->Show();
	close->Show();
	historyPanel->Hide();
	display_searched();

}

private:
	System::Void display_searched()
	{
		// Delete previous controls, if any (efficient use of memory)
		for each (Control ^ ctrl in frequentSearchPanel->Controls)
		{
			delete ctrl;
		}
		frequentSearchPanel->Controls->Clear();
		frequentSearchPanel->Width = 658;
		frequentSearchPanel->BackColor = Color::Transparent;
		frequentSearchPanel->Location = System::Drawing::Point(17, 60);
		frequentSearchPanel->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
		this->Controls->Add(frequentSearchPanel);
		List<HistoryObject> searched = sh->get_top5();
		for (int i = 0; i < searched.size(); ++i)
		{
			// Create a new Panel control for each contact
			Panel^ contactPanel = gcnew Panel();
			contactPanel->BackColor = System::Drawing::Color::White;
			contactPanel->Location = System::Drawing::Point(17, 90 + i * 120); // Adjust the Y position based on the index
			contactPanel->Size = System::Drawing::Size(658, 104);

			// Create and configure PictureBox
			PictureBox^ pictureBox = gcnew PictureBox();
			pictureBox->Location = System::Drawing::Point(17, 22);
			pictureBox->Size = System::Drawing::Size(48, 48);
			pictureBox->SizeMode = PictureBoxSizeMode::Zoom;
			pictureBox->ImageLocation = "user.png"; // Adjust the image location
			contactPanel->Controls->Add(pictureBox); // Add PictureBox to the panel

			// Create and configure Label for full name
			Label^ fullNameLabel = gcnew Label();
			fullNameLabel->AutoSize = true;
			fullNameLabel->Font = gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			fullNameLabel->ForeColor = System::Drawing::Color::MidnightBlue;
			fullNameLabel->Location = System::Drawing::Point(99, 22);
			fullNameLabel->Text = gcnew String((searched[i].get_contact().get_first_name() + " " + searched[i].get_contact().get_last_name()).c_str());
			contactPanel->Controls->Add(fullNameLabel); // Add Label to the panel

			// Create and configure Label for time
			Label^ TimeLabel = gcnew Label();
			TimeLabel->AutoSize = true;
			TimeLabel->Font = gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			TimeLabel->Location = System::Drawing::Point(99, 52);
			TimeLabel->Text = gcnew String((to_string(searched[i].get_time().get_hours()) + ":" + to_string(searched[i].get_time().get_minutes()) + ":" + to_string(searched[i].get_time().get_seconds())).c_str());
			contactPanel->Controls->Add(TimeLabel); // Add Label to the panel

			// Create and configure label for date
			Label^ DateLabel = gcnew Label();
			DateLabel->AutoSize = true;
			DateLabel->Font = gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			DateLabel->Location = System::Drawing::Point(99, 70);
			DateLabel->Text = gcnew String((to_string(searched[i].get_date().get_year()) + "/" + to_string(searched[i].get_date().get_month()) + "/" + to_string(searched[i].get_date().get_day())).c_str()); 
			contactPanel->Controls->Add(DateLabel); // Add Label to the panel
			frequentSearchPanel->Controls->Add(contactPanel);
		}
		frequentSearchPanel->AutoSize = true;
		frequentSearchPanel->AutoScroll = true;
	}
private: System::Void close_Click(System::Object^ sender, System::EventArgs^ e) {
	frequentSearchPanel->Hide();
	historyPanel->Show();
	close->Hide();
	frequent_search->Show();
}
};
}