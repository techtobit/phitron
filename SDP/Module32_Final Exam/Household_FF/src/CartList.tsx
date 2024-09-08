import axios from 'axios'
import React, { useEffect, useState } from 'react'


interface CartListState {
	"id": number,
	"customer": string,
	"service": number,
}

const CartList:React.FC =()=> {

	const[cartList, setCartList]= useState<CartListState>()

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





		</div>
	)
}

export default CartList;