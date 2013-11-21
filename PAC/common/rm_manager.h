/// @file rm_manager.h
/// @brief ����������� ���������������� ��������� ������ � ����������
/// �������������.
///
/// @author  ������ ������� ���������.
///
/// @par �������� �������� �������������:
/// @c DEBUG   - ���������� c ������� ���������� ���������� � �������.
///
/// @par ������� ������:
/// @$Rev: 678 $.\n
/// @$Author: id $.\n
/// @$Date:: 2013-05-29 16:44:39#$.

#ifndef RM_MANAGER_H
#define RM_MANAGER_H

#if !defined WIN_OS && !defined LINUX_OS && !defined MINIOS7
#error You must define OS!
#endif

#include <vector>

#include "s_types.h"

#include "rm_tech_def.h"
//-----------------------------------------------------------------------------
class rm_manager
    {
    public:
        /// @brief ����� ������� �� PAC.
        int evaluate();

        /// <summary>
        /// ���������� ���������� PAC ��� ����������.
        /// </summary>
        /// <param name="name">��� ���������� PAC.</param>
        /// <param name="IP_address">IP-����� ���������� PAC.</param>
        /// <returns></returns>
        void add_rm_cmmctr( char* name, char* IP_address, int remote_PAC_id );

        static rm_manager* get_instance()
            {
            return instance;
            }

        void print() const;

    private:
        rm_manager(): cmmctrs( std::vector< i_rm_cmmctr* >() )
            {                      
            }

        static rm_manager* instance;

        std::vector< i_rm_cmmctr* > cmmctrs;
    };
//-----------------------------------------------------------------------------
rm_manager* G_RM_MANAGER();

#endif // RM_MANAGER_H