import axios from 'axios'
import React, { useEffect, useState } from 'react'


interface CartListState {
	"id": number,
	"customer": string,
	"service": number,
	"category": string,
	"price": number
}

const CartList:React.FC =()=> {

	const[cartList, setCartList]= useState<CartListState[]>([])

	useEffect(() => {
		const fetchServices = async () => {
			try {
				const response = await axios.get(`http://127.0.0.1:8000/orders/cart/`)
				setCartList(response.data)
			} catch (error) {
				console.error(error)
			}
		}
		fetchServices()
	}, [])

	console.log(cartList);
	
	return (
		<div>

<div className="relative overflow-x-auto shadow-md sm:rounded-lg">
    <table className="w-full text-sm text-left rtl:text-right text-gray-500 dark:text-gray-400">
        <thead className="text-xs text-gray-700 uppercase bg-gray-50 dark:bg-gray-700 dark:text-gray-400">
            <tr>
                <th scope="col" className="px-6 py-3">
                    #ID Number
                </th>
                <th scope="col" className="px-6 py-3">
                    Service Provider
                </th>
                <th scope="col" className="px-6 py-3">
                    Category
                </th>
                <th scope="col" className="px-6 py-3">
                    Price
                </th>
                <th scope="col" className="px-6 py-3">
									Delete
                </th>
                <th scope="col" className="px-6 py-3">
									Order
                </th>
            </tr>
        </thead>
        <tbody>
					{
						cartList?.map((cart, idx)=> (
							<tr key={idx} className="bg-white border-b dark:bg-gray-800 dark:border-gray-700 hover:bg-gray-50 dark:hover:bg-gray-600">
							<th scope="row" className="px-6 py-4 font-medium text-gray-900 whitespace-nowrap dark:text-white">
									{cart.id}
							</th>
							<th scope="row" className="px-6 py-4 font-medium text-gray-900 whitespace-nowrap dark:text-white">
									{cart.customer}
							</th>
							<td className="px-6 py-4">
									{cart.category}
							</td>
							<td className="px-6 py-4">
							{cart.price}
							</td>
							<td className="px-6 py-4 ">
									<button  className="font-medium text-red-600 dark:text-red-500 hover:underline">Delete</button>
							</td>
							<td className="px-6 py-4 ">
									<a href="#" className="font-medium text-green-600 dark:text-green-500 hover:underline">Make Payment</a>
							</td>
					</tr>
						))
					}

        </tbody>
    </table>
</div>



		</div>
	)
}

export default CartList;