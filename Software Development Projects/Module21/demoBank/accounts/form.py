from django import forms 
from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth.models import User
from .constants import ACCOUNT_TYPE, GENDER_TYPE
from .models import UserBankAccount, UserAddress

class RegistrationsForm(UserCreationForm):
	birth_date = forms.DateField(widget=forms.DateInput(attrs={'type': 'date'}))
	gender = forms.ChoiceField(choices=GENDER_TYPE)
	account_type = forms.ChoiceField(choices=ACCOUNT_TYPE)
	country = forms.CharField(max_length=100)
	city = forms.CharField(max_length=50)
	street_address = forms.CharField(max_length=50)
	postal_code = forms.CharField(max_length=5)
	class Meta:
		model = User
		fields = ['username', 'password1', 'password2', 'first_name', 'last_name',
		'email', 'account_type', 'birth_date', 'gender', 'country', 
		'city', 'street_address', 'postal_code'
		]
	
	def save(self, commit = True):
		got_user = super(UserCreationForm, self).save(commit=False)
		if commit == True:
			#saved user data in user modal
			got_user.save()
			birth_date = self.cleaned_data.get('birth_date')
			gender = self.cleaned_data.get('gender')
			account_type = self.cleaned_data.get('account_type')
			country = self.cleaned_data.get('country')
			city = self.cleaned_data.get('city')
			street_address = self.cleaned_data.get('street_address')
			postal_code = self.cleaned_data.get('postal_code')

			UserBankAccount.objects.create(
				user = got_user,
				account_type = account_type,
				birth_date = birth_date,
				gender = gender,
				account_no = 1000000+got_user.id
			)

			UserAddress.objects.create(
				user = got_user,
				country = country,
				city = city,
				street_address = street_address,
				postal_code = postal_code
			)

			return got_user
	def __init__(self, *args, **kwargs):
		super().__init__(*args, **kwargs)

		for field in self.fields:
			self.fields[field].widget.attrs.update({
				'class' : (
					'appearance-none block w-full bg-gray-200 '
          'text-gray-700 border border-gray-200 rounded '
          'py-3 px-4 leading-tight focus:outline-none '
          'focus:bg-white focus:border-gray-500'
				)
			})
	
class UserUpdateForm(forms.ModelForm):
	account_type = forms.ChoiceField(choices=ACCOUNT_TYPE)
	gender = forms.ChoiceField(choices=GENDER_TYPE)
	birth_date = forms.DateField(widget=forms.DateInput(attrs={'type':'date'}))
	country = forms.CharField(max_length=100)
	city = forms.CharField(max_length=50)
	street_address = forms.CharField(max_length=50)
	postal_code = forms.IntegerField()

	class Meta:
		model = User
		fields = ['first_name', 'last_name', 'email']

	def __init__(self, *args, **kwargs):
		super().__init__(*args, **kwargs)
		for field in self.fields:
			self.fields[field].widget.attrs.update({
        'class': (
                    'appearance-none block w-full bg-gray-200 '
                    'text-gray-700 border border-gray-200 rounded '
                    'py-3 px-4 leading-tight focus:outline-none '
                    'focus:bg-white focus:border-gray-500'
        )
      })

		if self.instance:
			try:
				user_account = self.instance.account
				user_address = self.instance.address
			except UserBankAccount.DoesNotExist:
				user_account = None
				user_address = None
			if user_account:
				self.fields['account_type'].initial = user_account.account_type
				self.fields['gender'].initial = user_account.gender
				self.fields['birth_date'].initial = user_account.birth_date
				self.fields['country'].initial = user_address.country
				self.fields['city'].initial = user_address.city
				self.fields['street_address'].initial = user_address.street_address
				self.fields['postal_code'].initial = user_address.postal_code

	def save(self, commit = True):
		user = super().save(commit = False)
		if commit:
			user.save()
			
			user_account, created = UserBankAccount.objects.get_or_create(user=user)
			user_address, created = UserAddress.objects.get_or_create(user=user)

			user_account.account_type = self.cleaned_data['account_type']
			user_account.gender = self.cleaned_data['gender']
			user_account.birth_date = self.cleaned_data['birth_date']
			user_account.save()

			user_address.country = self.cleaned_data['country']
			user_address.city = self.cleaned_data['city']
			user_address.street_address = self.cleaned_data['street_address']
			user_address.postal_code = self.cleaned_data['postal_code']
			user_address.save()

		return user
