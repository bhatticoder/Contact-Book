#pragma once
#include "ContactsBook.h"
#include "Create_contact.h"
#include "Contact_details.h"
#include "List.h"
#include "AdvancedSearch.h"
#include "SearchHistory.h"
#include "Globals.h"
#include "InputDialog.h"

using namespace msclr::interop;

namespace ContactsApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ContactList : public System::Windows::Forms::Form
	{
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
		ContactsBook* book;
		AdvanceSearch* as;
		Create_contact^ cc;
		Contact_details^ cd;
		Panel^ mainContainer;
		Panel^ searchContainer;
		bool search_closed = false;

	private: System::Windows::Forms::ComboBox^ sort_by;
	private: System::Windows::Forms::Label^ sort_by_label;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ merge_duplicates;
	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::PictureBox^ back;
		   
	public:
		ContactList(void)
		{
			// Instantiate members
			book = new ContactsBook(50);
			as = new AdvanceSearch();
			mainContainer = gcnew Panel();
			searchContainer = gcnew Panel();
			book->load_from_file("write_contacts.txt");
			book->save_to_file("write_contacts.txt");
			InitializeComponent();
		}

		~ContactList()
		{
			if (components)
			{
				delete components;
				delete book;
				delete as;
			}
		}

	
	private: System::Windows::Forms::Label^ heading;


	private: System::Windows::Forms::Button^ add_button;
	private: System::Windows::Forms::TextBox^ search_field;
	private: System::Windows::Forms::PictureBox^ close;



	public: System::Windows::Forms::Panel^ search_bar;

	public:

		void display_results(List<Contact> results)
		{
			// Delete previous controls, if any (efficient use of memory)
			for each (Control ^ ctrl in searchContainer->Controls)
			{
				delete ctrl;
			}
			searchContainer->Controls->Clear();
			searchContainer->Width = 658;
			searchContainer->BackColor = Color::Transparent;
			searchContainer->Location = System::Drawing::Point(17, 60);
			searchContainer->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
			this->Controls->Add(searchContainer);
			heading->Text = "Search Results";
			mainContainer->Hide();
			mainContainer->Enabled = false;
			for (int i = 0; i < results.size(); ++i)
			{
				// Create a new Panel control for each contact
				Panel^ c_panel = gcnew Panel();
				c_panel->BackColor = System::Drawing::Color::White;
				c_panel->Location = System::Drawing::Point(17, 90 + i * 120); // Adjust the Y position based on the index
				c_panel->Size = System::Drawing::Size(658, 104);
				searchContainer->Controls->Add(c_panel);

				// Create and configure PictureBox
				PictureBox^ pictureBox = gcnew PictureBox();
				pictureBox->Location = System::Drawing::Point(17, 22);
				pictureBox->Size = System::Drawing::Size(48, 48);
				pictureBox->SizeMode = PictureBoxSizeMode::Zoom;
				pictureBox->ImageLocation = "user.png"; // Adjust the image location
				c_panel->Controls->Add(pictureBox); // Add PictureBox to the panel

				// Create and configure Label for full name
				Label^ fullNameLabel = gcnew Label();
				fullNameLabel->AutoSize = true;
				fullNameLabel->Font = gcnew System::Drawing::Font(L"Montserrat", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0));
				fullNameLabel->ForeColor = System::Drawing::Color::MidnightBlue;
				fullNameLabel->Location = System::Drawing::Point(99, 22);
				fullNameLabel->Text = gcnew String((results[i].get_first_name() + " " + results[i].get_last_name()).c_str());
				c_panel->Controls->Add(fullNameLabel); // Add Label to the panel


				// Create and configure Label for email_address
				Label^ email_label = gcnew Label();
				email_label->Location = System::Drawing::Point(410, 62);
				email_label->Text = gcnew String(results[i].get_email_address().c_str());
				email_label->Width = 200;
				c_panel->Controls->Add(email_label);

				// Create and configure Label for contact_id (hidden)
				Label^ id_label = gcnew Label();
				id_label->Location = System::Drawing::Point(400, 62);
				int id = results[i].get_contact_id();
				id_label->Text = id.ToString();
				id_label->Name = "id_label";
				id_label->Visible = false;
				c_panel->Controls->Add(id_label); 

				// Create and configure Label for phone number
				Label^ phoneNumberLabel = gcnew Label();
				phoneNumberLabel->AutoSize = true;
				phoneNumberLabel->Font = gcnew System::Drawing::Font(L"Montserrat", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0));
				phoneNumberLabel->Location = System::Drawing::Point(99, 62);
				phoneNumberLabel->Text = gcnew String(results[i].get_mobile_number().c_str()); 
				c_panel->Controls->Add(phoneNumberLabel); // Add Label to the panel
				
				// Add panel to searchContainer
				c_panel->Click += gcnew System::EventHandler(this, &ContactList::search_panel_Click);
			}
			searchContainer->AutoScroll = true;
			searchContainer->AutoSize = true;

		}

		System::Void search_panel_Click(System::Object^ sender, System::EventArgs^ e)
		{
				Panel^ clicked = dynamic_cast<Panel^>(sender);
				if (clicked == nullptr)
				{
					MessageBox::Show("clicked panel is null");
					return;
				}
				Label^ idLabel = dynamic_cast<Label^>(clicked->Controls["id_label"]);
				if (idLabel == nullptr)
				{
					MessageBox::Show("id label is null");
					return;
				}
				String^ id_str = idLabel->Text;
			if (!String::IsNullOrEmpty(id_str))
			{
				int id;
				try
				{
					id = System::Convert::ToInt32(id_str);
					cd = gcnew Contact_details(book->get_contact(id), *book);
					cd->hide_delete();
					cd->ShowDialog();
					cd->Focus();
					book->get_contact(id).add_search_count();
					HistoryObject current = as->search_history(book->get_contact(id));
					as->update_history(current, *sh);
					
					return;

				}
				catch (System::Exception^ e)
				{
					MessageBox::Show(e->Message);
				}
				catch (std::exception& e)
				{
					MessageBox::Show(marshal_as<String^>(e.what()));
				}
			}
			else {
				MessageBox::Show("id problem");
				return;
			}
		}

		void ContactList::DisplayContacts(ContactsBook *book)
		{
			// Delete previous controls, if any (efficient use of memory)
			for each (Control ^ ctrl in mainContainer->Controls)
			{
				delete ctrl;
			}
			mainContainer->Controls->Clear();
			mainContainer->Width = 658;
			mainContainer->BackColor = Color::Transparent;
			mainContainer->Location = System::Drawing::Point(17, 80);
			mainContainer->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
			this->Controls->Add(mainContainer);
			for (int i = 0; i < book->total_contacts(); ++i)
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
				fullNameLabel->Font = gcnew System::Drawing::Font(L"Montserrat", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0));
				fullNameLabel->ForeColor = System::Drawing::Color::MidnightBlue;
				fullNameLabel->Location = System::Drawing::Point(99, 22);
				fullNameLabel->Text = gcnew String(((*book)[i].get_first_name() + " " + (*book)[i].get_last_name()).c_str());
				contactPanel->Controls->Add(fullNameLabel); // Add Label to the panel

				// Create and configure Label for phone number
				Label^ phoneNumberLabel = gcnew Label();
				phoneNumberLabel->AutoSize = true;
				phoneNumberLabel->Font = gcnew System::Drawing::Font(L"Montserrat", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0));
				phoneNumberLabel->Location = System::Drawing::Point(99, 62);
				phoneNumberLabel->Text = gcnew String((*book)[i].get_mobile_number().c_str()); 
				contactPanel->Controls->Add(phoneNumberLabel); // Add Label to the panel

				// Create and configure Label for contact_id (hidden)
				Label^ id_label = gcnew Label();
				id_label->Location = System::Drawing::Point(400, 62);
				int id = (*book)[i].get_contact_id();
				id_label->Text = id.ToString();
				id_label->Name = "id_label";
				id_label->Visible = false;
				contactPanel->Controls->Add(id_label);

				contactPanel->Click += gcnew System::EventHandler(this, &ContactList::ContactPanel_Click);

				// Add panel to mainContainer
				mainContainer->Controls->Add(contactPanel);
			}
			mainContainer->AutoScroll = true;
			mainContainer->AutoSize = true;
			
		}

		// Control Panel click in mainContainer
		void ContactList::ContactPanel_Click(System::Object^ sender, System::EventArgs^ e)
		{
			// Cast the sender object to Panel^
			Panel^ clickedPanel = dynamic_cast<Panel^>(sender);
			if (clickedPanel == nullptr)
			{
				MessageBox::Show("Clicked panel is null");
				return;
			}

			// Retrieve the id_label from the clicked panel
			Label^ idLabel = dynamic_cast<Label^>(clickedPanel->Controls["id_label"]);
			if (idLabel == nullptr)
			{
				MessageBox::Show("ID label is null");
				return;
			}

			String^ id_str = idLabel->Text;
			if (!String::IsNullOrEmpty(id_str))
			{
				int id;
				try
				{
					id = System::Convert::ToInt32(id_str);
					Contact clicked = book->get_contact(id);
					cd = gcnew Contact_details(clicked, *book);
					cd->ShowDialog();
					cd->Focus();
					// Handle contact deletion
					if (cd->get_deleted())
					{
						DisplayContacts(this->book);
						cd->set_deleted(false);
					}
				}
				catch (System::Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}
				catch (std::exception& ex)
				{
					MessageBox::Show(marshal_as<String^>(ex.what()));
				}
			}
			else
			{
				MessageBox::Show("There is a problem with the contact ID");
			}
		}

		

		private:
		  
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ContactList::typeid));
			this->search_field = (gcnew System::Windows::Forms::TextBox());
			this->heading = (gcnew System::Windows::Forms::Label());
			this->search_bar = (gcnew System::Windows::Forms::Panel());
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->close = (gcnew System::Windows::Forms::PictureBox());
			this->back = (gcnew System::Windows::Forms::PictureBox());
			this->sort_by = (gcnew System::Windows::Forms::ComboBox());
			this->sort_by_label = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->merge_duplicates = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->search_bar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->close))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// search_field
			// 
			this->search_field->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->search_field->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->search_field->Enabled = false;
			this->search_field->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.249999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->search_field->ForeColor = System::Drawing::Color::Gray;
			this->search_field->Location = System::Drawing::Point(15, 8);
			this->search_field->Name = L"search_field";
			this->search_field->Size = System::Drawing::Size(280, 14);
			this->search_field->TabIndex = 0;
			this->search_field->Text = L"Search  contact...";
			this->search_field->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ContactList::search_field_KeyPress);
			// 
			// heading
			// 
			this->heading->AutoSize = true;
			this->heading->Font = (gcnew System::Drawing::Font(L"Montserrat", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->heading->Location = System::Drawing::Point(87, 26);
			this->heading->Name = L"heading";
			this->heading->Size = System::Drawing::Size(147, 26);
			this->heading->TabIndex = 0;
			this->heading->Text = L"Your Contacts";
			// 
			// search_bar
			// 
			this->search_bar->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->search_bar->Controls->Add(this->search_field);
			this->search_bar->Location = System::Drawing::Point(92, 77);
			this->search_bar->Name = L"search_bar";
			this->search_bar->Size = System::Drawing::Size(552, 31);
			this->search_bar->TabIndex = 2;
			this->search_bar->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ContactList::search_bar_MouseClick);
			// 
			// add_button
			// 
			this->add_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->add_button->BackColor = System::Drawing::Color::DarkCyan;
			this->add_button->FlatAppearance->BorderColor = System::Drawing::Color::DarkCyan;
			this->add_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add_button->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 8.249999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add_button->ForeColor = System::Drawing::Color::White;
			this->add_button->Location = System::Drawing::Point(453, 19);
			this->add_button->Name = L"add_button";
			this->add_button->Padding = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->add_button->Size = System::Drawing::Size(117, 33);
			this->add_button->TabIndex = 6;
			this->add_button->Text = L"Add Contact";
			this->add_button->UseVisualStyleBackColor = false;
			this->add_button->Click += gcnew System::EventHandler(this, &ContactList::add_button_Click);
			// 
			// close
			// 
			this->close->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"close.Image")));
			this->close->Location = System::Drawing::Point(699, 77);
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(21, 33);
			this->close->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->close->TabIndex = 7;
			this->close->TabStop = false;
			this->close->Visible = false;
			this->close->Click += gcnew System::EventHandler(this, &ContactList::close_Click);
			// 
			// back
			// 
			this->back->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back.Image")));
			this->back->Location = System::Drawing::Point(23, 30);
			this->back->Name = L"back";
			this->back->Size = System::Drawing::Size(27, 22);
			this->back->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->back->TabIndex = 8;
			this->back->TabStop = false;
			this->back->Click += gcnew System::EventHandler(this, &ContactList::back_Click);
			// 
			// sort_by
			// 
			this->sort_by->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->sort_by->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sort_by->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.249999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sort_by->FormattingEnabled = true;
			this->sort_by->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"First Name(A-Z)", L"First Name (Z-A)", L"Last Name (A-Z)",
					L"Last Name (Z-A)", L"Default"
			});
			this->sort_by->Location = System::Drawing::Point(92, 118);
			this->sort_by->Name = L"sort_by";
			this->sort_by->Size = System::Drawing::Size(115, 23);
			this->sort_by->TabIndex = 10;
			this->sort_by->SelectedIndexChanged += gcnew System::EventHandler(this, &ContactList::sort_by_SelectedIndexChanged);
			// 
			// sort_by_label
			// 
			this->sort_by_label->AutoSize = true;
			this->sort_by_label->Font = (gcnew System::Drawing::Font(L"Montserrat", 8.249999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sort_by_label->Location = System::Drawing::Point(29, 121);
			this->sort_by_label->Name = L"sort_by_label";
			this->sort_by_label->Size = System::Drawing::Size(48, 15);
			this->sort_by_label->TabIndex = 11;
			this->sort_by_label->Text = L"Sort By:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(699, 15);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(28, 40);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &ContactList::pictureBox1_Click);
			// 
			// merge_duplicates
			// 
			this->merge_duplicates->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->merge_duplicates->BackColor = System::Drawing::Color::LightBlue;
			this->merge_duplicates->Enabled = false;
			this->merge_duplicates->FlatAppearance->BorderColor = System::Drawing::Color::DarkGray;
			this->merge_duplicates->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->merge_duplicates->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 8.249999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->merge_duplicates->ForeColor = System::Drawing::Color::Black;
			this->merge_duplicates->Location = System::Drawing::Point(617, 61);
			this->merge_duplicates->Name = L"merge_duplicates";
			this->merge_duplicates->Padding = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->merge_duplicates->Size = System::Drawing::Size(144, 33);
			this->merge_duplicates->TabIndex = 13;
			this->merge_duplicates->Text = L"Merge Duplicates";
			this->merge_duplicates->UseVisualStyleBackColor = false;
			this->merge_duplicates->Visible = false;
			this->merge_duplicates->Click += gcnew System::EventHandler(this, &ContactList::merge_duplicates_Click);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::DarkCyan;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 8.249999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::DarkCyan;
			this->button1->Location = System::Drawing::Point(576, 19);
			this->button1->Name = L"button1";
			this->button1->Padding = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->button1->Size = System::Drawing::Size(117, 33);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Create group";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ContactList::button1_Click);
			// 
			// ContactList
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::AliceBlue;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(773, 469);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->merge_duplicates);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->sort_by_label);
			this->Controls->Add(this->sort_by);
			this->Controls->Add(this->back);
			this->Controls->Add(this->close);
			this->Controls->Add(this->add_button);
			this->Controls->Add(this->search_bar);
			this->Controls->Add(this->heading);
			this->Name = L"ContactList";
			this->Text = L"ContactList";
			this->Load += gcnew System::EventHandler(this, &ContactList::ContactList_Load);
			this->search_bar->ResumeLayout(false);
			this->search_bar->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->close))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ContactList_Load(System::Object^ sender, System::EventArgs^ e) {	
		this->Focus();
		searchContainer->Name = "search_container";
		DisplayContacts(this->book);
		cc = gcnew Create_contact(*book);
		search_field->Enabled = false;
		search_field->Text = "Search Contacts...";
		
	}

	   // Create contact button
private: System::Void add_button_Click(System::Object^ sender, System::EventArgs^ e) {
	cc->ShowDialog();
	cc->Focus();
	// If contact added, reprint the contacts
	if (cc->isAdded())
	{
		DisplayContacts(this->book);
		book->save_to_file("write_contacts.txt");
	}
	
}

private: System::Void search_bar_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	search_bar->Controls["search_field"]->Enabled = true;
	search_bar->Controls["search_field"]->Text = "";
}
private: System::Void search_field_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == (char)Keys::Enter) {
		// Enter search mode, if ENTER key pressed
		search_field->Enabled = false;
		this->BackColor = System::Drawing::Color::LightSteelBlue;
		String^ query = search_field->Text;
		close->Visible = true;
		sort_by_label->Visible = false;
		sort_by->Visible = false;
		searchContainer->Show();
		as->perform_search(marshal_as<std::string>(query), *book);
		List<Contact> results = as->get_results();
		display_results(results);
	}
}
private: System::Void close_Click(System::Object^ sender, System::EventArgs^ e) {
	searchContainer->Controls->Clear();
	searchContainer->Hide();
	mainContainer->Visible = true;
	mainContainer->Enabled = true;
	search_closed = true;
	this->BackColor = System::Drawing::Color::AliceBlue;
	close->Visible = false;
	heading->Text = "Your contacts";
	sort_by_label->Visible = true;
	sort_by->Visible = true;
}
	

	
private: System::Void back_Click(System::Object^ sender, System::EventArgs^ e) {
		ContactList::Close();

}

	
private: System::Void sort_by_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	// Sort function comboBox
	ComboBox^ comboBox = (ComboBox^)sender;
	int selectedIndex = comboBox->SelectedIndex;
	ContactsBook* sorted_copy = new ContactsBook(*book);
	switch (selectedIndex)
	{
	case 0:
		// First Name: Ascending
		sort_list(sorted_copy->get_contacts(), sorted_copy->total_contacts(), new Contact(), Contact::fn_less_than);
		DisplayContacts(sorted_copy);
		break;
	
	case 1:
		// First Name: Descending
		sort_list(sorted_copy->get_contacts(), sorted_copy->total_contacts(), new Contact(), Contact::fn_greater_than);
		DisplayContacts(sorted_copy);
		break;
	case 2:
		// Last Name: Ascending
		sort_list(sorted_copy->get_contacts(), sorted_copy->total_contacts(), new Contact(), Contact::ln_less_than);
		DisplayContacts(sorted_copy);
		break;
	case 3:
		// Last Name: Descending
		sort_list(sorted_copy->get_contacts(), sorted_copy->total_contacts(), new Contact(), Contact::ln_greater_than);
		DisplayContacts(sorted_copy);
		break;
	case 4:
		// Default
		DisplayContacts(this->book);
		break;
	}

}

private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (merge_duplicates->Visible == false)
	{
		merge_duplicates->Visible = true;
		merge_duplicates->Enabled = true;
	}
	else
	{
		merge_duplicates->Visible = false;
		merge_duplicates->Enabled = false;
	}
	
}
private: System::Void merge_duplicates_Click(System::Object^ sender, System::EventArgs^ e) {
	this->book->merge_duplicates();
	this->book->save_to_file("write_contacts.txt");
	DisplayContacts(this->book);
}

	 // Create groups button
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Form^ selectContactsForm = gcnew Form();
	selectContactsForm->Text = "Select Contacts";
	selectContactsForm->Size = System::Drawing::Size(300, 400);
	FlowLayoutPanel^ panel = gcnew FlowLayoutPanel();
	panel->Dock = DockStyle::Fill;
	selectContactsForm->Controls->Add(panel);
	for (int i = 0; i < book->total_contacts(); ++i) {
		CheckBox^ checkBox = gcnew CheckBox();
		checkBox->Text = gcnew String((book->get_contact(i).get_first_name() + " " + book->get_contact(i).get_last_name()).c_str());
		checkBox->Tag = i;
		panel->Controls->Add(checkBox);
	}
	Button^ confirmButton = gcnew Button();
	confirmButton->Text = "Confirm";
	confirmButton->Dock = DockStyle::Bottom;
	confirmButton->Click += gcnew EventHandler(this, &ContactList::confirmButton_Click);
	selectContactsForm->Controls->Add(confirmButton);
	selectContactsForm->ShowDialog();
}

private:
	System::Void confirmButton_Click(System::Object^ sender, System::EventArgs^ e) {
		InputDialog^ inputDialog = gcnew InputDialog("Enter Group Name", "Group Name:");
		if (inputDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
			String^ groupName = inputDialog->InputValue;
			if (!String::IsNullOrEmpty(groupName)) {
				Windows::Forms::DialogResult result = MessageBox::Show("Do you want to create a group with the selected contacts?", "Confirm Group Creation",
					MessageBoxButtons::YesNo, MessageBoxIcon::Question);
				if (result == Windows::Forms::DialogResult::Yes) {
					MessageBox::Show("Group created successfully!");
					return;
					this->Close();
					inputDialog->Close();
				}
			}
			else {
				MessageBox::Show("Group name cannot be empty. Group creation canceled.");
				return;
				this->Close();
				inputDialog->Close();
			}
		}
		else {
			MessageBox::Show("Group creation canceled.");
			return;
			this->Close();
			inputDialog->Close();
		}
	}
};
}

