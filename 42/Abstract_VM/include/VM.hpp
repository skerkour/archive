/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 08:49:04 by skerkour          #+#    #+#             */
/*   Updated: 2016/04/01 08:49:04 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_HPP
# define VM_HPP

#include <memory>
#include <vector>

#include "IOperand.hpp"

class VM {

public:
    VM();
    ~VM();


private:
    std::vector<std::unique_ptr<IOperand>> _instructions;
    
};

#endif // VM_HPP
