//===- Operators.cpp ---------------------------------------------*- C++-*-===//
//
//  Copyright (C) 2015, 2016  Federico Iannucci (fed.iannucci@gmail.com)
//
//  This file is part of Clang-Chimera.
//
//  Clang-Chimera is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Affero General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Clang-Chimera is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Affero General Public License for more details.
//
//  You should have received a copy of the GNU Affero General Public License
//  along with Clang-Chimera. If not, see <http://www.gnu.org/licenses/>.
//
//===----------------------------------------------------------------------===//
/// \file Operators.cpp
/// \author Federico Iannucci
/// \brief This file contains sample operators
//===----------------------------------------------------------------------===//

#include "Operators/Examples/Mutators.h"
#include "Operators/Examples/Operators.h"

::std::unique_ptr<::chimera::m_operator::MutationOperator>
chimera::examples::getROROperator() {
  ::std::unique_ptr<::chimera::m_operator::MutationOperator> Op(
      new ::chimera::m_operator::MutationOperator(
          "ExampleROROperator",   // Operator identifier
          "Sample Operator: ROR", // Description
          false) // It is NOT a HOM Operator (default:false). It could be
                 // omitted.
      );

  // Add mutators to the current operator
  Op->addMutator(
      ::chimera::m_operator::MutatorPtr(new ::chimera::examples::MutatorGreaterOpReplacement()));

  // Return the operator
  return Op;
}