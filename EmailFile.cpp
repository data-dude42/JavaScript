#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <cstring>
#include "EmailFile.h"

using namespace std;
namespace seneca
{

    Email &Email::operator=(const Email &rhs)
    {

        if (this != &rhs && rhs.m_email && rhs.m_name)
        {
            delete[] m_email;
            m_email = nullptr;
            m_email = new char[strlen(rhs.m_email) + 1];
            strcpy(m_email, rhs.m_email);
            delete[] m_name;
            m_name = nullptr;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
            strcpy(m_year, rhs.m_year);
        }

        return *this;
    }

    bool Email::load(std::ifstream &in)
    {

        char buffer[BUFFER_SIZE];
        bool result = false;

        if (in.getline(buffer, BUFFER_SIZE, ','))
        {
            delete[] m_email;
            m_email = new char[strlen(buffer) + 1];
            strcpy(m_email, buffer);

            if (in.getline(buffer, BUFFER_SIZE, ','))
            {
                delete[] m_name;
                m_name = new char[strlen(buffer) + 1];
                strcpy(m_name, buffer);

                if (in.getline(buffer, BUFFER_SIZE, '\n'))
                {
                    strcpy(m_year, buffer);
                    result = true;
                }
            }
        }

        return result;
    }

    Email::~Email()
    {
        delete[] m_name;
        delete[] m_email;
    }

    void EmailFile::setFilename(const char *filename)
    {
        delete[] m_filename;
        m_filename = nullptr;
        if (filename)
        {
            m_filename = new char[strlen(filename) + 1];
            m_filename[0] = '\0';
            strcpy(m_filename, filename);
        }
    }

    void EmailFile::setEmpty()
    {
        delete[] m_emailLines;
        delete[] m_filename;
        m_emailLines = nullptr;
        m_filename = nullptr;
        m_noOfEmails = 0;
    }

    bool EmailFile::setNoOfEmails()
    {

        bool isValid = false;
        ifstream file(m_filename);

        if (!file.is_open())
        {
            cout << "Failed to open file: " << m_filename << endl;
        }
        else
        {
            m_noOfEmails = 0;
            while (file)
            {
                m_noOfEmails += (file.get() == '\n');
            }
            file.close();

            if (m_noOfEmails == 0)
            {
                delete[] m_filename;
                m_filename = nullptr;
            }
            else
            {
                m_noOfEmails++;
                isValid = true;
            }
        }
        return isValid;
    }

    EmailFile::EmailFile()
    {
        m_emailLines = nullptr;
        m_filename = nullptr;
        m_noOfEmails = 0;
    }

    EmailFile::EmailFile(const char *filename)
    {
        if (filename)
        {
            setFilename(filename);
            setNoOfEmails();
            loadEmails();
        }
    }

    EmailFile::EmailFile(const EmailFile &other)
    {
        operator=(other);
    }

    EmailFile::~EmailFile()
    {
        delete[] m_emailLines;
        delete[] m_filename;
        m_emailLines = nullptr;
        m_filename = nullptr;
    }

    void EmailFile::loadEmails()
    {
        bool success = true;
        int num_success_email{};
        if (m_filename)
        {
            delete[] m_emailLines;
            m_emailLines = new Email[m_noOfEmails];
            ifstream file(m_filename);

            for (int i = 0; i < m_noOfEmails && success; i++)
            {
                Email temp;
                if (temp.load(file))
                {
                    m_emailLines[i] = temp;
                    ++num_success_email;
                }
                else
                {
                    success = false;
                }
            }
        }
        m_noOfEmails = num_success_email;
    }

    bool EmailFile::saveToFile(const char *filename) const
    {
        bool backValue = true;
        ofstream file(filename);
        if (file.is_open())
        {
            for (int i = 0; i < m_noOfEmails; i++)
            {
                file << m_emailLines[i].m_email << "," << m_emailLines[i].m_name << "," << m_emailLines[i].m_year << endl;
            }
        }
        else
        {
            cout << "Error:Could not open file: " << filename << endl;
            backValue = false;
        }
        return backValue;
    }

    void EmailFile::fileCat(const EmailFile &obj, const char *name)
    {
        int index = 0;
        if (m_emailLines && obj)
        {
            int totalEmails = m_noOfEmails + obj.m_noOfEmails;
            Email *newobj = new Email[totalEmails];

            for (int i = 0; i < m_noOfEmails; i++)
            {
                newobj[index++] = m_emailLines[i];
            }

            for (int i = 0; i < obj.m_noOfEmails; i++)
            {
                newobj[index++] = obj.m_emailLines[i];
            }

            delete[] m_emailLines;
            m_emailLines = newobj;
            m_noOfEmails = totalEmails;

            if (name && name[0])
            {
                delete[] m_filename;
                m_filename = new char[strlen(name) + 1];
                strcpy(m_filename, name);
            }
            ofstream file(m_filename);
            for (int i = 0; i < m_noOfEmails; i++)
            {
                file << m_emailLines[i].m_email << "," << m_emailLines[i].m_name << "," << m_emailLines[i].m_year << endl;
            }
        }
    }

    EmailFile::operator bool() const
    {
        return m_filename != nullptr && m_noOfEmails > 0;
    }

    void EmailFile::operator=(const EmailFile &other)
    {
        if (*this != other && other.m_filename != nullptr && other.m_noOfEmails > 0)
        {
            delete[] m_emailLines;
            m_emailLines = nullptr;
            delete[] m_filename;
            m_filename = nullptr;
            m_noOfEmails = 0;
            setFilename(other.m_filename);
            m_noOfEmails = other.m_noOfEmails;
            m_emailLines = new Email[m_noOfEmails];
            int i = 0;
            while (i < m_noOfEmails)
            {
                m_emailLines[i] = other.m_emailLines[i];
                i++;
            }
        }
    }

    std::ostream &EmailFile::view(std::ostream &ostr) const
    {
        if (m_filename)
        {
            ostr << m_filename << endl;
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl;
            ostr.fill(' ');
            for (int i = 0; i < m_noOfEmails; i++)
            {
                ostr.width(35);
                ostr.setf(ios::left);
                ostr << m_emailLines[i].m_email;
                ostr.width(25);
                ostr << m_emailLines[i].m_name;
                ostr << "Year = " << m_emailLines[i].m_year << endl;
            }
        }
        return ostr;
    }

    std::ostream &operator<<(std::ostream &ostr, const EmailFile &text)
    {
        return text.view(ostr);
    }

}